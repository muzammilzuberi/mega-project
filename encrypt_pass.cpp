#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
int main()
{
	char password[50]={0};
	int aux_password[50]={0};
	char encrypted_password2[100]={0};
	char final_encryption[100]={0};
	ofstream fout;
	fout.open("pass.txt",ios::out);

	cout<<"Type a password to encrypt (0-9,A-Z,a-z): ";
	cin>>password;


	for(int i=0;i<(strlen(password)*2);i++)
	{
		aux_password[i]=password[i]+7;
		encrypted_password2[2*i+1]=aux_password[i];
		encrypted_password2[2*i]=i+189;
		final_encryption[i]=encrypted_password2[i];
		fout<<final_encryption[i];
	}
	
	fout.close();
	
	char str[20];	
	ifstream fin;
	fin.open("pass.txt",ios::in);
	cout<<"\nEnter pass to match: ";
	cin>>password;
	
	fin>>str;
	
	if(strcmp(str,password))
	{
		cout<<"correct pass";
	}
	else
	cout<<"incorrect pass";
}
