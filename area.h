#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

class Area
{
	string area;
	float factor;

	public:
		string get_area()
		{
			return area;
		}
    
	    void set_area(const string town)
		{
			this->area=area;
		}	    
		
		void initializing_file()
		{
			ofstream fout;
	        int x;
	        cout<<"Enter the No. of Area you need to Add:";
			cin>>x;
	        fout.open("Area.txt",ios::out | ios::binary);
	        for(int i=0;i<x;i++)
	        {
		        cin.ignore();
	
		        cout<<"Enter Area Name:"<<endl;
		        getline(cin,area);
		        
				cout<<"Enter Factor:"<<endl;
		        cin>>factor;
		        
		        fout<<area<<"\t";
		        fout<<factor;
		       	fout<<"\n";
    	}
    
        fout.close();
        
    }
		
	void add_new_area()
	{
		ofstream fout;
        int x;
        cout<<"Enter the No. of Area you need to Add:";
		cin>>x;
        fout.open("Area.txt",ios::binary | ios::app);
        for(int i=0;i<x;i++)
        {
	        cin.ignore();

	        cout<<"Enter Area Name:"<<endl;
	        getline(cin,area);
	        
			cout<<"Enter Factor:"<<endl;
	        cin>>factor;
	        
	        fout<<area<<"\t";
	        fout<<factor;
	       	fout<<"\n";
		}

    	fout.close(); 
    }
	
		
	float get_area_factor(string fareaname)
	{
		ifstream fin;
		fin.open("Area.txt",ios::in|ios::binary);

		
		while(!fin.eof())
		{
			getline(fin,area,'\t');
			fin>>factor;
			
			fin.ignore();
			
			
			if(area==fareaname)
			{
				return factor;
			}
		}
		cout<<endl<<"Record Not Found";
		return 0;
	}
		
		void set_factor(string farea)
		{
		bool flag=false;
		Area a;
		Area temp;
		
		ifstream fin;
		fin.open("Area.txt",ios::in);
		ofstream fout;
		fout.open("temp.txt",ios::out);
		
		if(fin.fail())
		cout<<"File not found"<<endl;
			
			while (!fin.eof())
			{
				getline(fin,area,'\t');
				fin>>factor;
				if(area==farea)  
				{	
			        cout<<"Enter Factor:"<<endl;
			        cin>>factor;			        
			        fout<<area<<"\t";
			        fout<<factor<<endl;
					flag=true;
				}
				else
				{
			        fout<<area<<"\t";
			        fout<<factor;
				}
			}
		
			fin.close();
			fout.close();
		
		if(flag==true)	
		{
			remove("Area.txt");			
  			rename("temp.txt","Area.txt");
			cout<<"Record updated"<<endl;
		}
		else
		cout<<"Record not found"<<endl;
	}
	
	void view_all_records()
	{
	
		ifstream fin;
		fin.open("Area.txt",ios::in|ios::binary);
		int i;
		while(!fin.eof())
		{
			getline(fin,area,'\t');
			fin>>factor;
//			cout<<i<<endl;
			fin.ignore();			
			if(i==10)
			cout<<area<<endl;
			++i;
		}
	}
					
};
