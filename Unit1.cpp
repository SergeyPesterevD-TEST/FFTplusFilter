//---------------------------------------------------------------------------

#include <vcl.h>
#include <math.h>
#include <fftw3.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Chart"
#pragma link "Series"
#pragma link "TeEngine"
#pragma link "TeeProcs"
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
double Re = 0, Im = 0, summaRe = 0, summaIm = 0, Ak[512] = {0}, Ak_1[512] = {0}, Arg = 0;
float massiv[1000];

for (int i = 0; i < Memo1->Lines->Count; i++)
{
massiv[i]=StrToFloat(Memo1->Lines->Strings[i]);
}

for (int i = 0; i < 512; i++)
{
summaRe = 0; summaIm = 0;
for (int j = 0; j < 512; j++)
{
Arg = 2.0*M_PI*j*i/512.0;
Re = cos(Arg)*(massiv[j]);
Im = sin(Arg)*(massiv[j]);
summaRe = summaRe + Re;
summaIm = summaIm + Im;
}
Ak[i] = sqrt(summaRe*summaRe + summaIm*summaIm);
}

for (int i = 3; i < 512; i++) { Series1->AddXY(i,Ak[i]); }

for (int i = 0; i < Memo2->Lines->Count; i++)
{
massiv[i]=StrToFloat(Memo2->Lines->Strings[i]);
}

for (int i = 0; i < 512; i++)
{
summaRe = 0; summaIm = 0;
for (int j = 0; j < 512; j++)
{
Arg = 2.0*M_PI*j*i/512.0;
Re = cos(Arg)*(massiv[j]);
Im = sin(Arg)*(massiv[j]);
summaRe = summaRe + Re;
summaIm = summaIm + Im;
}
Ak[i] = sqrt(summaRe*summaRe + summaIm*summaIm);
}

for (int i = 3; i < 512; i++) { Series2->AddXY(i,Ak[i]); }



}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
double Re = 0, Im = 0, summaRe = 0, summaIm = 0, Ak[1024] = {0}, Ak_1[1024] = {0}, Arg = 0;
float massiv[1024];

for (int i = 0; i < 512; i++)
{
massiv[i]=sin(i*10*M_PI/512);
}

for (int i = 0; i < 512; i++)
{
massiv[i]=massiv[i]+sin(i*2*M_PI/512);
}

for (int i = 0; i < 1024; i++)
{
summaRe = 0; summaIm = 0;
for (int j = 0; j < 512; j++)
{
Arg = 2.0*M_PI*j*i/512.0;
Re = cos(Arg)*(massiv[j]);
Im = sin(Arg)*(massiv[j]);
summaRe = summaRe + Re;
summaIm = summaIm + Im;
}
Ak[i] = sqrt(summaRe*summaRe + summaIm*summaIm);
}

//for (int i = 0; i < 512; i++) { Series1->AddXY(i,massiv[i]); }
for (int i = 0; i < 1024; i++) { Series1->AddXY(i,Ak[i]); }
}
//---------------------------------------------------------------------------

