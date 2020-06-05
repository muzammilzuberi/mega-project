#include<iostream>
#include<fstream>
//#include<fstream>
//#include "area.h"
//#include "type.h"
//#include "capacity.h"
using namespace std;
void validate_year(int year){
	try{
		if ((year>2000)&&(year<2020)){
			throw false;		
		}	
	}
	catch(bool x){
		if(x==false){
			cout<<"Invalid Year Please Enter Again"<<endl;
		}
	}
}

using namespace std;
class Date
{
	int day;
	int month;
	int year;
	
	public:
	void set_date()
	{
		cout<<"Enter year: ";
		cin>>year;
		validate_year(year);
		//validate year
		cout<<"Enter month: ";
		cin>>month;
		//validate month
		cout<<"Enter day: ";
		cin>>day;
		//validate day, check one week before 
	}
	//check_avialability
	void check_availablity(){
			string fvenuename;
			int fday,fmonth,fyear;
			bool found=false;
			ifstream input("Dates.txt");
			while(!input.eof()){
				input>>fvenuename>>fday>>fmonth>>fyear;
				if(fday==day){
					if(fmonth==month){
						if(fyear==year){
							found=true;
							break;
						}
					}
				}
			}
			if(found==true){
				cout<<"Venue Already Booked Please Try Other Dates";
			}
			else{
				int choice;
				cout<<"Do You Want To Book ? Yes/No "<<endl<<"1 : Yes "<<endl<<"2 : No "<<endl;
				cin>>choice;
				switch(choice){
					case 1 : addbookingdate();
					break ;
					case 2 : set_date();
					break;
				}
			}
			input.close();
		}
	void addbookingdate(){
		ofstream output("Dates.txt",ios::app);
		output<<endl/*name*/<<"\t"<<day<<" "<<month<<" "<<year;
		output.close();
	}
};
int main(){
	Date d;
	d.set_date();
	d.check_availablity();
}

