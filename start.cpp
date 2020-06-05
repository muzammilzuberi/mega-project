#include<iostream>
#include<fstream>
#include "area.h"
#include "type.h"
#include "capacity.h"


using namespace std;

class Add_On
{
    string category;  
    string type;

    int calculate_cost_of_addon();
    void set_addon_data(string category,string type);
    void calculate_addon_price();
    int get_addon_price()const;
};


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
		//validate year
		cout<<"Enter month: ";
		cin>>month;
		//validate month
		cout<<"Enter day: ";
		cin>>day;
		//validate day, check one week before 
		
		//check_avialability
	}
};



class Cost
{
    int price;

    protected:
    void set_cost(int);
    
    public: 
	int get_cost()const;
    void add_price_of_addson(const Add_On adds_on,string category,string type); 
};

class Customer_Cost : public Cost
{
	public:
    void calculate_cost(const Type venue_type, const Capacity cap,const Area location,Date date); 
	
		
};


class Owner_Cost : public Cost
{
	public:
    void calculate_cost(const Type venue_type, const Capacity cap,const Area location); 
	
};

void Owner_Cost :: calculate_cost(Type venue_type, const Capacity cap,const Area location) 
{
	int price=0;
	price+=venue_type.get_base_cost(venue_type.get_type());
	price*=location.get_area_factor();
	price+=cap.get_capacity_cost(venue_type.get_type());
	
	set_cost(price);				
}

void Cost:: set_cost(int price)
{
    this->price=price;
}

int Cost::get_cost()const
{
    return price;
}




class Venue
{
	protected:	
    Type venue_type;
    Capacity cap;
    Area location;
    Add_On adds_on;

    bool booking_status;
    string name;

    public:
    virtual void input_data()=0;
    virtual void add_record(ofstream &fout)=0;

    void get_record(ifstream &fin);
    void output_data();

//	void test()
//	{
//		cout<<location.get_town();
//	}

};

class Customer: public Venue
{
	Customer_Cost cost;
	
	public: 
	void input_data();
//    void add_record(ofstream &fout);                                                                                             
//	void test2()
//	{
//		cout<<location.get_town();
//	}
	

};

class Venue_Owner : public Venue
{
	Owner_Cost cost;
	
	public: 
	void input_data();
    void add_record(ofstream &fout);                                                                                             

};

void Customer::input_data()
{
	ofstream fout;
	Date date;
	
	fout.open("data.txt",ios::out | ios::binary);
    int price,capacity;
	string type,area;

    cout<<"Enter Venue Type:";
    cin.ignore();
    getline(cin,type);
    
    venue_type.set_type(type);
    
    cout<<"Enter Venue Name:";
    cin.ignore();
    getline(cin,name);

    
    cout<<"Enter Venue Capacity:";
    cin>>capacity;
    
    cap.set_capacity(capacity);
    
    cout<<"Enter Venue Area:";
    cin>>area;
    location.set_area(area);
    
    date.set_date();
    
//    add_record(fout);

    fout.close();
}

void Venue_Owner::input_data()
{
	ofstream fout;
	
	fout.open("data.txt",ios::out | ios::binary);
    int price,capacity;
	string type,area;

    cout<<"Enter Venue Type:";
    cin.ignore();
    getline(cin,type);
    
    venue_type.set_type(type);
    
    cout<<"Enter Venue Name:";
    cin.ignore();
    getline(cin,name);

    
    cout<<"Enter Venue Capacity:";
    cin>>capacity;
    
    cap.set_capacity(capacity);
    
    cout<<"Enter Venue Area:";
    cin>>area;
    
    location.set_area(area);
    
    cost.calculate_cost(venue_type,cap,location);
    
    cout<<"This is the estimated rent we can offer for your venue"<<endl;
    cout<<"Would you like to confirm the venue?";
    
    cout<<"Are you sure?";
    
//    add_record(fout);

    fout.close();
}


void Venue_Owner :: add_record(ofstream &fout)
{
    fout.seekp(0,ios::end);
    fout<<venue_type.get_type();
	fout<<"\t";
    fout<<name;
    fout<<"\t";
    fout<<location.get_area();
    fout<<cap.get_capacity();
    fout<<"\t";
	
    fout<<cost.get_cost();    
    fout<<"\n";
    
    
}

void  Venue::get_record(ifstream &fin)
{
    
}
void Venue::output_data()
{
	ifstream fin;
	fin.open("data.txt",ios::in);

    get_record(fin);


	fin.close();	
}

 
int main()
{
	Type obj;
	Capacity obj2;
	obj.set_type("Diamond Marquee");
	cout<<obj.get_base_cost(obj.get_type())<<endl;

	cout<<obj2.get_cph(obj.get_type());
	
}
