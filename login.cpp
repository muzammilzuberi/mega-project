#include<iostream>
#include<fstream>
#include <string>
#include <windows.h>

using namespace std;
class Login
{
	protected:
	string name,email;
	string password;
	public:
};
class ExistingUser:public Login
{
	public:

	void authentication()
	{
		bool found=false;
		string useremail,userpassword;
		
		cout<<"Enter email: ";
		cin>>email;
		cout<<"Enter password: ";
		cin>>password;
		
		ifstream input("LoginLogs.txt");
		while(!input.eof())
		{
			input>>email>>password;
			if(useremail==email)
			{
				
				if(userpassword==password)
				{
					found=true;
					break;
				}
				else
				{
					cout<<"Wrong password";
				}
			}
			else
			{
				cout<<"Email address doesnot exist in system"<<endl;
			}
		}
		if(found==true)
		{
			system("cls");
			cout<<"Welcome "<<name<<"!!";
		}
		else{
			cout<<"User Not Present,Please Create Account First";
		}
	}
};
class NewUser:public Login
{
	long int cnic;
	int cellphone;
	char gender;
	public:

	void adduser()
	{
		ofstream output("LoginLogs.txt",ios::app);
		if(!output)
		{	
			cout<<"File Not Opened";
		}
		output<<endl<<name<<"\t"<<password<<"\t"<<gender<<"\t"<<cnic<<"\t"<<cellphone;
		output.close();
	}
	
	void input_user()
	{
		cout<<"Please Enter your full name: \n";
		cin>>name;
		
		cin.ignore();
		
		cout<<"Enter your email address: \n";
		cin>>email;

		cin.ignore();
		
		cout<<"Please Enter Your Password: \n",
		cin>>password;				
		cout<<"Gender: \n";
		cin>>gender;
		cout<<"CNIC:  \n";
		cin>>cnic;
		cout<<"\nCellphone : \n+92";
		cin>>cellphone;
		adduser();		
	}

};
int main()
{
	int choice;
	cout<<"1.Existing User\n2.New User";
	cin>>choice;
	if(choice==1)
	{
		ExistingUser* obj;
		obj= new ExistingUser[1];
		obj->authentication();	
	}
	else
	{
		NewUser* obj;
		obj= new NewUser[1];
		obj->input_user();
	}
}
