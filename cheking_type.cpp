#include<iostream>
#include<limits>
using namespace std;

int main()
{
	int num;
	
	while (cout << "Enter a number: " && !(cin >> num)) 
	{
		cin.clear(); //clear bad input flag
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
		cout << "Invalid input; please re-enter.\n";
	}
	cout<<num;
}
