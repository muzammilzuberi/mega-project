#include<iostream>
#include<fstream>
using namespace std;
class Login{
	string name;
	string password;
	public:
		Login(){
			
		}
		Login(string n,string p){
			name=n;
			password=p;
		}
		set_name(string n){
			name=n;
		}
		set_pass(string p){
			password=p;
		}
		string get_name(){
			return name;
		}
		string get_pass(){
			return password;
		}
};
class ExistingUser:public Login{
	string username;
	string userpassword; 
	public:
		ExistingUser(string n,string p){
			username=n;
			userpassword=p;
		}
		void authentication(){
			bool found=false;
			string filename,filepassword,filegender,filefathername,filecnic,filecellphone;
			ifstream input("LoginLogs.txt");
			while(!input.eof()){
				input>>filename>>filepassword>>filegender>>filefathername>>filecnic>>filecellphone;
				if(username==filename){
					if(userpassword==filepassword){
						found=true;
						break;
					}
				}
			}
			if(found==true){
				system("cls");
				cout<<"Welcome "<<filename<<"!!";
			}
			else{
				cout<<"User Not Present,Please Create Account First";
			}
		}
};
class NewUser:public Login{
	string fathername;
	int cnic;
	int cellphone;
	string gender;
	public:
		NewUser(){
		}
		NewUser(string n,string p,string fn,string g,int cnic,int c):Login(n,p){
			this->fathername=fn;
			this->cnic=cnic;
			this->gender=g;
			this->cellphone=c;
		}
		void adduser(){
			ofstream output("LoginLogs.txt",ios::app);
			if(!output){
				cout<<"File Not Opened";
				exit(1);
			}
			output<<endl<<get_name()<<"\t"<<get_pass()<<"\t"<<fathername<<"\t"<<gender<<"\t"<<cnic<<"\t"<<cellphone;
			output.close();
		}
};
int main(){
	int choice;
	cout<<"1 : New user\n2 : Existing User";
	cin>>choice;
	if(choice==1){
				string n,p,g,f;
				int cnic,num;
				cout<<"Please Enter your name";cin>>n;
				cout<<"\nPlease Enter Your Password : ";cin>>p;
				cout<<"\nGender : ";cin>>g;
				cout<<"\nFather Name : ";cin>>f;
				cout<<"\nCNIC : ";cin>>cnic;
				cout<<"\nCellphone : ";cin>>num;
				NewUser n1(n,p,g,f,cnic,num);
				n1.adduser();	
	}
	else{
				string name1,password;
				cout<<"Please Enter Your Name And Password";
				cin>>name1>>password;
				ExistingUser n2(name1,password);
				n2.authentication();
	}
}
