#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

class Capacity
{
    int max_capacity;
    int min_capacity;
    static int range;
    int cost_per_head;

	int get_cph(string type_name)
	{
		int rent;
		string type;
		ifstream fin;
		fin.open("Type.txt",ios::in|ios::binary);
		
		while(!fin.eof())
		{

			getline(fin,type,'\t');
			fin>>rent;
			fin>>cost_per_head;
							
			if(type==type_name)
			{
				return cost_per_head;
			}
		}
		cout<<endl<<"Record Not Found";
		return 0;
	}

    
    public: 
    void set_capacity(int cap);
	int get_capacity()
	{
		return min_capacity;
	}
	
	int get_capacity_cost(string str)
	{
		return min_capacity*get_cph(str);	
	}	


};

void Capacity::set_capacity(int cap)
{
	max_capacity=cap+range;
	min_capacity=cap;
}

int Capacity:: range;

