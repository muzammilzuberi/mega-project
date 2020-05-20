#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

int round(int n) 
{ 
    int a = (n / 10000) * 10000; 
      
    int b = a + 10000; 
  
    return (n - a > b - n)? b : a; 
} 

int main()
{
	 string level;
	 float area;					//give each area a factor from (1-4)
	 int capacity,cph=0;			//cph: capacity per head
	 int daystogo=30;
	 bool weekend;
	 int base=0;
	 int total;
	 
	cin>>level;
	if(level=="gold")
	{
		base=100000;
		cph=450;
	}
	else if(level=="platinium")
	{
		cph=600;
		base=125000;
	}
	else if(level=="diamond")
	{
		base=150000;
		cph=750;
	}
	cout<<cph<<"\t\t"<<base<<endl;
	while(1)
	{		
		cout<<"Enter capacity and area: "<<endl;
		cin>>capacity;
		cin>>area; 
		total=(base*area)+(capacity*cph)+(50000/daystogo);
		
		cout<<"total: "<<round(total)<<endl;
	}
}
