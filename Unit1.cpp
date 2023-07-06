//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	F1rot = F2rot = Z1 = Z2 =
		F1Z1 = F1Z2 = F2Z1 = F2Z2 = Fx1 = Fx2 = 0;


}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit17KeyPress(TObject *Sender, System::WideChar &Key)
{//
    if((Key>='0')&&(Key<='9'))return;
	else if((Key==',')||(Key=='.')){Key=','; return ;}
	else if (Key==VK_BACK)return;
	else Key=0;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::GroupBox3Click(TObject *Sender)
{
  F1rot = (StrToFloat(Form1-> Edit17->Text))/60;
  Z1 = StrToFloat(Form1-> Edit19->Text);
  Z2 = StrToFloat(Form1-> Edit20->Text);
  if((F1rot != 0)&&(Z1 != 0)&&(Z2 != 0)){
	F2rot = CalcF2(F1rot,Z1,Z2);
	Form1-> Edit18->Text = FloatToStr((RoundTo(F2rot,-2)*60));
	F1Z1 =  F1rot*Z1;
	F1Z2 =  F1rot*Z2;
	F2Z1 =  F2rot*Z1;
	F2Z2 =  F2rot*Z2;
	Form1-> Edit1->Text = FloatToStr(RoundTo(F1rot,-2));
	Form1-> Edit2->Text = FloatToStr(RoundTo(F2rot,-2));
	Form1-> Edit3->Text = FloatToStr(RoundTo(F1Z1,-2));
	Form1-> Edit4->Text = FloatToStr(RoundTo(F1Z2,-2));
	Form1-> Edit5->Text = FloatToStr(RoundTo(F2Z1,-2));
	Form1-> Edit6->Text = FloatToStr(RoundTo(F2Z2,-2));
  }
}
//---------------------------------------------------------------------------
 double  TForm1::CalcF2(double f1,double z1, double z2)
 {
	return ((f1*z1)/z2);
 }
 //---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{ //PORT OPEN / CLOSE
	  AnsiString portname = ComboBox1->Text;
	  if(statusPort == false){  //port closed
	  if((comMoxa->Open(portname,57600)) == true)
		{
		   Button1->Caption = "закрыть";
		   ProgressBar1->Position = 100;
		   Button2->Enabled = true;
		   Memo2->Lines->Add("порт открыт");
		   statusPort = true;
		   Button4->Enabled=true;
		}
	  }
	  else{
		   comMoxa->Close();
		   Button1->Caption = "открыть";
		   ProgressBar1->Position = 0;
		   Button2->Enabled = false;
		   Memo2->Lines->Add("порт закрыт");
		   statusPort = false;
		   Button4->Enabled=false;
	  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{// SEND FREQ
	 int lenght = 0;
	 char printArray[4] = {0};
	 double data[8] = {0};
	 AnsiString stringResult = "F";//признак что далее идут частоты

	 readDataFromEdits(data);

	 for(int i = 0;i <8;i++){
		sprintf(printArray,"%04.2f;",data[i]);
		stringResult+=printArray;
	 }

	 stringResult+="C"; //end of array
	 lenght = stringResult.Length();
	 Memo2->Lines->Add("отправка данных:");
	 Memo2->Lines->Add(stringResult);
	 comMoxa->SendData(stringResult.c_str(),lenght);
	 Sleep(1000);
	 Memo2->Lines->Add("конец передачи");

	 for(int i = 0; i < sizeof(printArray); i++){ printArray[i] = 0;};
	 Sleep(500);
	 comMoxa-> ReadData(printArray,sizeof(printArray));
	 String s = printArray;
	 Sleep(500);
	 if((strstr(printArray, "FC"))!= NULL){	Memo2->Lines->Add("данные приняты успешно"); }
	 else Memo2->Lines->Add("требуется повтор передачи");

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{// SEND phase

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Memo2DblClick(TObject *Sender)
{
    Memo2->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{//read EEPROM data
	char rx_array[250] = {0};
	double freq[8] = {0};
	char result[16] = {0};
	int numInArray = 0;

	AnsiString stringResult = "FC";
	Memo2->Lines->Add("read EEPROM: START");
	comMoxa->SendData(stringResult.c_str(),stringResult.Length());
	Sleep(1000);

	comMoxa-> ReadData(rx_array,sizeof(rx_array));

	for(int n = 0; n < (sizeof(freq))/4; n++)//парсим
	{
		numInArray = getPosInArray(rx_array,sizeof(rx_array));
		for(int i = 0; i<numInArray; i++){ result[i] = rx_array[i];};
		freq[n] = (atof(result));//kHz
		for(int i = 0; i < sizeof(result); i++){ result[i] = 0; }//очистка
		for(int i = 0; i < ((sizeof(rx_array))-numInArray); i++)
			{ rx_array[i] = rx_array[i+numInArray+1]; }//сдвиг массива
	}

	writeDataInEdits(freq);
	Memo2->Lines->Add("read EEPROM: END");
}
//---------------------------------------------------------------------------
int TForm1::readDataFromEdits(double *dat_array)
{
	 dat_array[0] = RoundTo((StrToFloat(Edit1->Text)),-2);
	 dat_array[1] = RoundTo((StrToFloat(Edit2->Text)),-2);
	 dat_array[2] = RoundTo((StrToFloat(Edit3->Text)),-2);
	 dat_array[3] = RoundTo((StrToFloat(Edit4->Text)),-2);
	 dat_array[4] = RoundTo((StrToFloat(Edit5->Text)),-2);
	 dat_array[5] = RoundTo((StrToFloat(Edit6->Text)),-2);
	 dat_array[6] = RoundTo((StrToFloat(Edit7->Text)),-2);
	 dat_array[7] = RoundTo((StrToFloat(Edit8->Text)),-2);
	 return  0;
 }
//---------------------------------------------------------------------------
int TForm1::writeDataInEdits(double *dat_array)
{//
	Form1-> Edit1->Text = FloatToStr(RoundTo(dat_array[0],-2));
	Form1-> Edit2->Text = FloatToStr(RoundTo(dat_array[1],-2));
	Form1-> Edit3->Text = FloatToStr(RoundTo(dat_array[2],-2));
	Form1-> Edit4->Text = FloatToStr(RoundTo(dat_array[3],-2));
	Form1-> Edit5->Text = FloatToStr(RoundTo(dat_array[4],-2));
	Form1-> Edit6->Text = FloatToStr(RoundTo(dat_array[5],-2));
	return 0;
}
//---------------------------------------------------------------------------
int TForm1::getPosInArray(char *array, int size)
{   char *tst = new char[5];
	char test [10] = {0};
	int i=0;
	for(i = 0; i < size ; i++){
		if(array[i] == 0x3B){ return i; }
	}
 //	delete tst;
//   return 0;
	test [11] = 2;

}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button5Click(TObject *Sender)
{
char *X = new char;


}
//---------------------------------------------------------------------------

