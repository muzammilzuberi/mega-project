#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;


class Type
{
    string type;
    int rent;
    public:
    void set_type(string type)
    {
        this->type=type;
    }
    
    string get_type()
    {
        return type;
    }

	int get_base_cost(string type_name)
	{
		ifstream fin;
		fin.open("Type.txt",ios::in|ios::binary);
		int cph;
				
		while(!fin.eof())
		{
			getline(fin,type,'\t');
			fin>>rent;
			fin>>cph;
			fin.ignore();	
											
			if(type==type_name)
			{
				return rent;
			}
		}
		cout<<endl<<"Record Not Found";
		return 0;
	}

	void set_rentprice(string type_name)
	{
		bool flag=false;		
		ifstream fin;
		fin.open("Type.txt",ios::in);
		ofstream fout;
		fout.open("temp.txt",ios::out);
		int cph;
		
		if(fin.fail())
		cout<<"File not found"<<endl;
			
			while (!fin.eof())
			{
				getline(fin,type,'\t');
				fin>>rent;
				fin>>cph;
				if(type==type_name)  
				{	
			        cout<<"Enter Rent:"<<endl;
			        cin>>rent;			        
			        fout<<type<<"\t";
			        fout<<rent<<"\t";
			        fout<<cph<<endl;
					flag=true;
				}
				else
				{
			        fout<<type<<"\t";
			        fout<<rent<<"\t";
			        fout<<cph<<endl;
				}
		}
	
		fin.close();
		fout.close();
		
		if(flag==true)	
		{
			remove("Type.txt");			
			rename("temp.txt","Type.txt");
			cout<<"Record updated"<<endl;
		}
		else
		cout<<"Record not found"<<endl;
	}

};

