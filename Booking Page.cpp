#include<iostream>
#include<fstream>
using namespace std;
class Rent{
	string venue;
	int rent;
	int capacity_rph;
	public:
		void set_venue(string x){
			venue=x;
		}
		string get_venue(){
			return venue;
		}
		void set_rent(int x){
			rent=x;
		}
		int get_rent(){
			return rent;
		}
		void set_capacity_rph(int x){
			capacity_rph=x;
		}
		int get_capacity_rph(){
			return capacity_rph;
		}
		
		void set_rentprice(string fvenuename,int frent){
			Rent r[12];
			bool found=false;
			int foundindex,i=0;
			ifstream input ("Venue.txt");
			while(!input.eof()){
				input>>r[i].venue>>r[i].rent;
				if(r[i].venue==fvenuename){
					foundindex=i;
					found=true;
				}
				++i;
			}
			if(found==true){
			r[foundindex].set_rent(frent);
			ofstream output("Venue.txt");
				for(int i=0;i<12;i++){
					output<<endl<<r[i].get_venue()<<"\t"<<r[i].get_rent();	
				}
				output.close();
				cout<<endl<<"Record Successfully Updated";
			}
			else{
				cout<<"Record Not Found"<<endl;
			}
		}
		void set_rateperhead(string fvenuename,int frph){
			Rent r[12];
			bool found=false;
			int foundindex,i=0;
			ifstream input ("Capacity.txt");
			while(!input.eof()){
				input>>r[i].venue>>r[i].capacity_rph;
				if(r[i].venue==fvenuename){
					foundindex=i;
					found=true;
				}
				++i;
			}
			if(found==true){
			r[foundindex].set_capacity_rph(frph);
			ofstream output("Capacity.txt");
				for(int i=0;i<12;i++){
					output<<endl<<r[i].get_venue()<<"\t"<<r[i].get_capacity_rph();	
				}
				output.close();
				cout<<endl<<"Record Successfully Updated";
			}
			else{
				cout<<"Record Not Found"<<endl;
			}
		}
		int get_rentprice(string fvenuename){
			Rent r[12];
			bool found=false;
			int foundindex,i=0;
			ifstream input ("Venue.txt");
			while(!input.eof()){
				input>>r[i].venue>>r[i].rent;
				if(r[i].venue==fvenuename){
					foundindex=i;
					found=true;
					break;
				}
				++i;
			}
			if(found==true){
				cout<<endl<<"Record Found";
				return r[foundindex].get_rent();
			}
			else{
				cout<<endl<<"Record Not Found";
			}
		}
		
	int get_rateperhead(string fvenuename){
		Rent r[12];
		bool found=false;
		int foundindex,i=0;
		ifstream input ("Capacity.txt");
		while(!input.eof()){
			input>>r[i].venue>>r[i].capacity_rph;
			if(r[i].venue==fvenuename){
				foundindex=i;
				found=true;
				break;
			}
			++i;	
		}
		if(found==true){
			cout<<endl<<"Record Found";
				return r[foundindex].get_capacity_rph();
		}
			else{
				cout<<endl<<"Record Not Found";
			}
		}
		
};
int main(){
	string name;
	Rent r;
	cout<<"Enter Venue Name"<<endl;
	cin>>name;
	//For Rent
	r.set_rentprice(name,1500);
	cout<<endl<<r.get_rentprice(name);
	//For Capacity Per Head
	r.set_rateperhead(name,5);
	cout<<endl<<r.get_rateperhead(name);
}


