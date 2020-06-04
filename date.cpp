#include <iostream>
#include<ctime>
#include<time.h>
using namespace std;

class date
{
	int day;
	int month;
	int year;
	public: 
	void set_date()
	{
		cout<<"Enter year: ";
		cin>>year;
		validateyear(year);
		cout<<"Enter month: ";
		cin>>month;
		validatemonth(month);
		cout<<"Enter day: ";
		cin>>day;
		validateday(day);
		//check one week before 
		
		//check_avialability
	}
	void validateyear(int x) throw(bool)
	{
		bool found=false;
		 try {
            if(!(x>=2000&&x<=2020))
                throw true;
        } catch (bool) {
            if(found==false)
            {
                cout<<"Invalid Year, Please Enter again!";
                cin>>year;
                
                validateyear(year);
        }
        }
	
	}
	
	void validatemonth(int x) throw(bool)
	{
		bool found=false;
		 try {
            if(!(x>=0&&x<=12))
                throw true;
        } catch (bool) {
            if(found==false)
            {
                cout<<"Invalid Month, Please Enter again!";
                cin>>month;
                
                validatemonth(month);
        }
        }
	
	}
	
		void validateday(int x) throw(bool)
	{
		bool found=false;
		 try {
            if(!(x>=0&&x<=31))
                throw true;
        } catch (bool) {
            if(found==false)
            {
                cout<<"Invalid Date, Please Enter again!";
                cin>>day;
                
                validateday(day);
        }
        }
	
	}
	
	int get_day()
	{
		return day;
	}
	
	int get_month()
	{
		return month;
	}
	
	int get_year()
	{
		return year;
	}
	
};

int main()
{    
	time_t theTime = time(NULL);
	struct tm *aTime = localtime(&theTime);
	
	date d;
	int x,y;
	
	
	int day = aTime->tm_mday;
	int month = aTime->tm_mon + 1; 
	int year = aTime->tm_year + 1900;		
	cout<<"Current date"<<endl;
	cout<<year<<"/"<<month<<"/"<<day<<endl;
	d.set_date();
	x=d.get_day()-day;
	
	
	if((x>=7)&&(d.get_month()>=month)&&(d.get_year()>year))
	{
		cout<<"Booking possible";
	}
	else
	{
		cout<<"Booking! Not possible";
	}
	
}

