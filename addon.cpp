#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

class Add_On
{
    string type;
    int price;
    
    public:
    	
    		void initializing_file()
		{
			ofstream fout;
	        int x;
	        cout<<"Enter the No. of Add Ons you need to Add:";
			cin>>x;
	        fout.open("Addon.txt",ios::out | ios::binary);
	        for(int i=0;i<x;i++)
	        {
		        cin.ignore();
	
		        cout<<"Enter Add-On:"<<endl;
		        getline(cin,type);
		        
				cout<<"Enter Price:"<<endl;
		        cin>>price;
		        
		        fout<<type<<"\t";
		        fout<<price;
		       	fout<<"\n";
    	}
    
        fout.close();
        
    }

    int calculate_cost_of_addon();
    
    void set_addon_data(string ftype)
    {
    		bool flag=false;
		 
		Add_On temp;
		
		ifstream fin;
		fin.open("Addon.txt",ios::in);
		ofstream fout;
		fout.open("temp.txt",ios::out);
		
		if(fin.fail())
		cout<<"File not found"<<endl;
			
			while (!fin.eof())
			{
				getline(fin,type,'\t');
				fin>>price;
				if(type==ftype)  
				{	
			        cout<<"Enter Price:"<<endl;
			        cin>>price;			        
			        fout<<type<<"\t";
			        fout<<price<<endl;
					flag=true;
				}
				else
				{
			        fout<<type<<"\t";
			        fout<<price;
				}
			}
		
			fin.close();
			fout.close();
		
		if(flag==true)	
		{
			remove("Addon.txt");			
  			rename("temp.txt","Addon.txt");
			cout<<"Record updated"<<endl;
		}
		else
		cout<<"Record not found"<<endl;
	}
    void calculate_addon_price();
    
    int get_addon_price(string ftype)
    {
    	
		ifstream fin;
		fin.open("Addon.txt",ios::in|ios::binary);

		
		while(!fin.eof())
		{
			getline(fin,type,'\t');

			fin>>price;
			
			fin.ignore();
			
			
			if(type==ftype)
			{
				return price;
			}
			fin.close();
		}
		cout<<endl<<"Record Not Found";
		return 0;
	}
	
		void view_all_records()
	{
	
		ifstream fin;
		fin.open("Addon.txt",ios::in|ios::binary);
		int i;
		while(!fin.eof())
		{
			getline(fin,type,'\t');
			fin>>type;
//			cout<<i<<endl;
			fin.ignore();			
			if(i==10)
			cout<<type<<endl;
			++i;
		}
	}
};

int main()
{
	Add_On a;
	string x;
	string type;
	//cin>>type;
	//a.initializing_file();
	cout<<"Type";
	cin>>type;
	a.set_addon_data(type);
	x=a.get_addon_price(type);
	
}
