#include <iostream>
#include<ctime>
#include<time.h>
using namespace std;

string currentTime()
{
    time_t now = time(0);
    struct tm  tstruct;
    char buf[6];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%H:%M", &tstruct);
    cout<<buf;
    return buf;
}
string currentDate()
{
    time_t now = time(0);
    struct tm  tstruct;
    char buf[20];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y/%m/%d", &tstruct);
    cout<<buf;
   return buf;
}

int main()
{

//        time_t curr_time;
//        curr_time = time(NULL);
//
//        char *tm = ctime(&curr_time);
//        cout << "Today is : " << tm;
//
//        return 0;
    
    currentTime();
    cout<<endl;
    currentDate();
    cout<<endl;
}
