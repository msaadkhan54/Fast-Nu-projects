#include<iostream>
using namespace std;

struct vehicle{
	int registrationNum;
	string ownerName;
	int model;
};

int main(){
	struct vehicle v1;
	cout<<"Enter registration number: ";
	cin>>v1.registrationNum;
	cout<<"Enter Owner name: ";
	cin>>v1.ownerName;
	cout<<"Enter Model: ";
	cin>>v1.model;
	
	cout<<"The registration num is "<<v1.registrationNum<<endl;
	cout<<"The Owner name is "<<v1.ownerName<<endl;
	cout<<"The model of vehicle is "<<v1.model;
}

