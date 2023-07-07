//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ComCtrls.hpp>

#include "stdlib.h"
#include "string.h"
#include "SysUtils.hpp"
#include <Windows.h>
#include "Math.h"
#include "math.hpp"
#include <TChar.h>
#include <io.h>
#include <fcntl.h>

#include "MySerialClass.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GroupBox1;
	TLabel *Label1;
	TComboBox *ComboBox1;
	TButton *Button1;
	TProgressBar *ProgressBar1;
	TLabel *Label2;
	TGroupBox *GroupBox2;
	TMemo *Memo1;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TLabel *Label10;
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit3;
	TEdit *Edit4;
	TEdit *Edit5;
	TEdit *Edit6;
	TEdit *Edit7;
	TEdit *Edit8;
	TLabel *Label11;
	TLabel *Label12;
	TLabel *Label13;
	TLabel *Label14;
	TLabel *Label15;
	TLabel *Label16;
	TLabel *Label17;
	TLabel *Label18;
	TEdit *Edit9;
	TEdit *Edit10;
	TEdit *Edit11;
	TEdit *Edit12;
	TEdit *Edit13;
	TEdit *Edit14;
	TEdit *Edit15;
	TEdit *Edit16;
	TLabel *Label19;
	TLabel *Label20;
	TLabel *Label21;
	TLabel *Label22;
	TLabel *Label23;
	TLabel *Label24;
	TLabel *Label25;
	TLabel *Label26;
	TButton *Button2;
	TButton *Button3;
	TProgressBar *ProgressBar2;
	TGroupBox *GroupBox3;
	TLabel *Label27;
	TLabel *Label28;
	TLabel *Label29;
	TLabel *Label30;
	TEdit *Edit17;
	TEdit *Edit18;
	TEdit *Edit19;
	TEdit *Edit20;
	TLabel *Label31;
	TLabel *Label32;
	TMemo *Memo2;
	TButton *Button4;
	TButton *Button5;
	void __fastcall Edit17KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall GroupBox3Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Memo2DblClick(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);

private:	// User declarations
public:
		double F1rot;
		double F2rot;
		double Z1;
		double Z2;
		double F1Z1;
		double F1Z2;
		double F2Z1;
		double F2Z2;
		double Fx1;
		double Fx2;

		double CalcF2(double f1,double z1, double z2);
    	bool statusPort;
		CSerial *comMoxa = new CSerial;
		int readDataFromEdits(double *dat_array);
		int writeDataInEdits(double *dat_array);
		int getPosInArray(char *array, int size);


	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
