#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

class Area{
	string area;
	float factor;
	int rent;

	public:
		void set_area(string area){
			this->area=area;
		}
		string get_area(){
			return area;
		}

		void set_factor(int x){
			factor=x;
		}
		float get_factor(){
			return factor;
		}
		
		void initializing_file()
		{
			ofstream fout;
        int x;
        cout<<"Enter the No. of Area you need to Add:";
		cin>>x;
        fout.open("Area.txt",ios::out | ios::binary | ios::app );
        
        for(int i=0;i<x;i++)
        {
	        cout<<"Enter Area Name:"<<endl;
	        cin.ignore();
	        cin>>area;

			cout<<"Enter Factor:"<<endl;
	        cin>>factor;
	        
	        fout<<area<<"\t";
	        fout<<factor;
	
	       //	fout.write((char*)this, sizeof(*this));
	       	fout<<"\n";
    	}
    
        fout.close();
        
    }
		
	
		
	float get_factor(string fareaname){
		Area r[12];
		bool found=false;
		int foundindex,i=0;
		ifstream fin;
		fin.open("Area.txt",ios::in|ios::binary);
		
		while(!fin.eof()){
			fin>>r[i].area>>r[i].factor;
			if(r[i].area==fareaname){
				foundindex=i;
				found=true;
				break;
			}
			++i;	
		}
		if(found==true){
			cout<<endl<<"Record Found";
				return r[foundindex].get_factor();
		}
			else{
				cout<<endl<<"Record Not Found";
			}
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

		fin.read((char*)this, sizeof(*this));
		if(fin.fail())
		cout<<"File not found"<<endl;
			
			while (!fin.eof())
			{
				cout<<"*";
				if(a.area==farea)  
				{	
				cout<<"1";
			        cout<<"Enter Factor:"<<endl;
			        cin>>temp.factor;
			        
			       	fout.write((char*)&temp,sizeof(temp));
					flag=true;
				}
				else
				{
					
				   	fout.write((char*)this, sizeof(*this));					
				}
				fin.read((char*)this, sizeof(*this));
			}
		
			fin.close();
			fout.close();
		
		if(flag==true)	
		{
			remove("Area.txt");			
  			rename("temp.txt","record.txt");
			cout<<"Record updated"<<endl;
		}
		else
		cout<<"Record not found"<<endl;
}
			
		
		
};
int main(){
	string name;
	Area a;
	a.initializing_file();
	cout<<"-------------"<<endl;
	cout<<"Enter Area Name"<<endl;
	cin>>name;


	a.set_factor(name);
	cout<<endl<<a.get_factor(name);


}
