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
int get_year()
{
 time_t now = time(0);
 tm *ltm = localtime(&now);
 int y;
 y=1900 + ltm->tm_year;	
 this->year=y;	
 return year;
}
	
int get_month()	
{
 time_t now = time(0);
 tm *ltm = localtime(&now);
 int m;
 m=1 + ltm->tm_mon;	
 this->month=m;	
 return month;	
}

int get_day()	
{
 time_t now = time(0);
 tm *ltm = localtime(&now);
 int d;
 d=ltm->tm_mday;	
 this->day=d;	
 return day;
}
};
	
//string currentTime()
//{
//    time_t now = time(0);
//    struct tm  tstruct;
//    char buf[6];
//    tstruct = *localtime(&now);
//    strftime(buf, sizeof(buf), "%H:%M", &tstruct);
//    cout<<buf;
//    return buf;
//}



int main()
{

int y,m,d;
date date;
m=date.get_month();
d=date.get_day();
y=date.get_year();
cout<<y<<"/"<<m<<"/"<<d;
}






