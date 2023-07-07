#ifndef __MYSERIALCLASS_H__
#define __MYSERIALCLASS_H__

#define FC_DTRDSR       0x01
#define FC_RTSCTS       0x02
#define FC_XONXOFF      0x04
#define ASCII_BEL       0x07
#define ASCII_BS        0x08
#define ASCII_LF        0x0A
#define ASCII_CR        0x0D
#define ASCII_XON       0x11
#define ASCII_XOFF      0x13

class CSerial
{
public:
	CSerial();
	~CSerial();
	BOOL __fastcall Open( String PortName, int nBaud  );
	BOOL __fastcall Close( void );
	int __fastcall ReadData  (   void *, int );
	int __fastcall SendData( char *, int );
	int __fastcall RxDataWaiting( void );
	BOOL __fastcall IsOpened( void ){ return( m_bOpened ); }
protected:
	BOOL __fastcall WriteCommByte( unsigned char );
	HANDLE m_hIDComDev;
	OVERLAPPED m_OverlappedRead, m_OverlappedWrite;
	BOOL m_bOpened;
};
#endif
