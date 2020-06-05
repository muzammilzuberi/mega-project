#include<iostream>
#include<conio.h>
#include<windows.h>
#include<cstdlib>
#include <cwchar>
using namespace std;

void front()
{
//	CONSOLE_FONT_INFOEX cfi;
//	cfi.cbSize = sizeof(cfi);
//	cfi.nFont = 0;
//	cfi.dwFontSize.X = 0;                   // Width of each character in the font
//	cfi.dwFontSize.Y = 24;                  // Height
//	cfi.FontFamily = FF_DONTCARE;
//	cfi.FontWeight = FW_NORMAL;
//	wcscpy(cfi.FaceName, L"Consolas"); // Choose your font
//	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
//	cout << "Font: Consolas, Size: 24\n";
	system("color 50");
	char a=219;
	cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t\t   LOADING! \n";
	cout<<"\t\t\t  ";
	for(int i=0;i<=18;i++)
	{
		cout<<a;
		Sleep(50);
	}
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\t\t\t------------VENUE BOOKING MANAGEMENT SYSTEM----------";
	cout<<"\n\n\n\t\t\tDesigned By:\n\n\t\t\tMohib-ur-Rehman\t\t19K-1364\t\t\t\t\n\t\t\tZoha Mobin\t\t19k-1469\t\t\t\t\t\n\t\t\tMuzammil Arif Zuberi\t19K-0342\n\n";
	cout<<"\t\t\t------------------------------------------------------"<<endl;
	cout<<"\t\t\t\t\tPress Any Key To Begin";
	
	getch();
	
}

int main()
{
	front();
	system("color 50");
	again:
		system("cls");
}
