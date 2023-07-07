#include "MySerialClass.h"
//************************************************
CSerial::CSerial()
{
	memset( &m_OverlappedRead, 0, sizeof( OVERLAPPED ) );
 	memset( &m_OverlappedWrite, 0, sizeof( OVERLAPPED ) );
	m_hIDComDev = NULL;
	m_bOpened = FALSE;	
	PurgeComm(m_hIDComDev,PURGE_TXCLEAR|PURGE_RXCLEAR);
};
//************************************************
CSerial::~CSerial()
{	
	Close();
};
//************************************************
BOOL __fastcall CSerial::Open( String PortName, int nBaud )
{
	if( m_bOpened ) return( TRUE );	
	DCB dcb;
	m_hIDComDev = CreateFile( PortName.c_str(), GENERIC_READ | GENERIC_WRITE, 0, NULL, 
							OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL |FILE_FLAG_OVERLAPPED, NULL);
	if( m_hIDComDev == NULL ) return( FALSE );

	memset( &m_OverlappedRead, 0, sizeof( OVERLAPPED ) );
 	memset( &m_OverlappedWrite, 0, sizeof( OVERLAPPED ) );

	COMMTIMEOUTS CommTimeOuts;
	CommTimeOuts.ReadIntervalTimeout = 0xFFFFFFFF;
	CommTimeOuts.ReadTotalTimeoutMultiplier = 0;
	CommTimeOuts.ReadTotalTimeoutConstant = 0;
	CommTimeOuts.WriteTotalTimeoutMultiplier = 0;
	CommTimeOuts.WriteTotalTimeoutConstant = 5000;
	SetCommTimeouts( m_hIDComDev, &CommTimeOuts );

	m_OverlappedRead.hEvent  = CreateEvent( NULL, TRUE, FALSE, NULL );
	m_OverlappedWrite.hEvent = CreateEvent( NULL, TRUE, FALSE, NULL );

	dcb.DCBlength = sizeof( DCB );
	GetCommState( m_hIDComDev, &dcb );
	dcb.BaudRate = nBaud;
	dcb.ByteSize = 8;	
	dcb.fBinary = TRUE;                   //включаем двоичный режим обмена
	dcb.fOutxCtsFlow = FALSE;             //выключаем режим слежения за сигналом CTS
	dcb.fOutxDsrFlow = FALSE;             //выключаем режим слежения за сигналом DSR
	dcb.fDtrControl = DTR_CONTROL_ENABLE; //отключаем использование линии DTR
	dcb.fDsrSensitivity = FALSE;          //отключаем восприимчивость драйвера к состоянию линии DSR
	dcb.fNull = FALSE;                    //разрешить приём нулевых байтов
	dcb.fRtsControl = RTS_CONTROL_DISABLE;//отключаем использование линии RTS
	dcb.fAbortOnError = FALSE;            //отключаем остановку всех операций чтения/записи при ошибке                                
	dcb.Parity = 0;                       //отключаем проверку чётности
	dcb.StopBits = 0;                     //задаём один стоп-бит                                
	                                   
	unsigned char ucSet;
	ucSet = (unsigned char) ( ( FC_RTSCTS & FC_DTRDSR ) != 0 );
	ucSet = (unsigned char) ( ( FC_RTSCTS & FC_RTSCTS ) != 0 );
	ucSet = (unsigned char) ( ( FC_RTSCTS & FC_XONXOFF ) != 0 );
	if( !SetCommState( m_hIDComDev, &dcb ) ||
		!SetupComm( m_hIDComDev, 10000, 10000 ) ||
		m_OverlappedRead.hEvent == NULL ||
		m_OverlappedWrite.hEvent == NULL )
	{
		DWORD dwError = GetLastError();
		if( m_OverlappedRead.hEvent != NULL ) CloseHandle( m_OverlappedRead.hEvent );
		if( m_OverlappedWrite.hEvent != NULL ) CloseHandle( m_OverlappedWrite.hEvent );
		CloseHandle( m_hIDComDev );
		return( FALSE );
	}
	m_bOpened = TRUE;
	return( m_bOpened );
};
//************************************************
BOOL __fastcall CSerial::Close( void )
{
	if( !m_bOpened || m_hIDComDev == NULL ) return( TRUE );
	if( m_OverlappedRead.hEvent != NULL ) CloseHandle( m_OverlappedRead.hEvent );
	if( m_OverlappedWrite.hEvent != NULL ) CloseHandle( m_OverlappedWrite.hEvent );
	CloseHandle( m_hIDComDev );
	m_bOpened = FALSE;
	m_hIDComDev = NULL;
	PurgeComm(m_hIDComDev,PURGE_TXCLEAR|PURGE_RXCLEAR);
	return( TRUE );
};
//************************************************
BOOL __fastcall CSerial::WriteCommByte( unsigned char ucByte )
{
	BOOL bWriteStat;
	DWORD dwBytesWritten;
	bWriteStat = WriteFile( m_hIDComDev, (LPSTR) &ucByte, 1, &dwBytesWritten, &m_OverlappedWrite );
	if( !bWriteStat && ( GetLastError() == ERROR_IO_PENDING ) )
	{
		if( WaitForSingleObject( m_OverlappedWrite.hEvent, 1000 ) ) dwBytesWritten = 0;
		else
		{
			GetOverlappedResult( m_hIDComDev, &m_OverlappedWrite, &dwBytesWritten, FALSE );
			m_OverlappedWrite.Offset += dwBytesWritten;
		}
	}
	return( TRUE );
};
//************************************************
int __fastcall CSerial::SendData(  char *buffer, int size )
{
	if( !m_bOpened || m_hIDComDev == NULL ) return( 0 );
	DWORD dwBytesWritten = 0;	
	for(int i=0; i<size; i++ )
	{
		WriteCommByte( buffer[i] );
		dwBytesWritten++;
	}
	return( (int) dwBytesWritten );
};
//************************************************
int __fastcall CSerial::RxDataWaiting( void )
{
	if( !m_bOpened || m_hIDComDev == NULL ) return( 0 );
	DWORD dwErrorFlags;
	COMSTAT ComStat;
	ClearCommError( m_hIDComDev, &dwErrorFlags, &ComStat );
	return( (int) ComStat.cbInQue );
};
//************************************************
int __fastcall CSerial::ReadData  ( void *buffer, int limit )
{
	if( !m_bOpened || m_hIDComDev == NULL ) return( 0 );
	BOOL bReadStatus;
	DWORD dwBytesRead, dwErrorFlags;
	COMSTAT ComStat;
	ClearCommError( m_hIDComDev, &dwErrorFlags, &ComStat );
	if( !ComStat.cbInQue ) return( 0 );
	dwBytesRead = (DWORD) ComStat.cbInQue;
	if( limit < (int) dwBytesRead ) dwBytesRead = (DWORD) limit;
	bReadStatus = ReadFile( m_hIDComDev, buffer, dwBytesRead, &dwBytesRead, &m_OverlappedRead );
	if( !bReadStatus )
	{
		if( GetLastError() == ERROR_IO_PENDING )
		{
			WaitForSingleObject( m_OverlappedRead.hEvent, 2000 );
			return( (int) dwBytesRead );
		}
		return( 0 );
	}
	return( (int) dwBytesRead );
};

