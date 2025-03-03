#include<iostream>
using namespace std;

class Car{
	int car_number;
	char car_model[10];
	
	public:
		void getdata();
		void showdata();
};

void Car::getdata(){
	cout<<"Enter car number : ";
	cin>>car_number;
	cout<<"Vintage car model : ";
	cin>>car_model;
}

void Car::showdata(){
	cout<<"Car number is "<<car_number<<endl;
	cout<<"Car model is "<<car_model;
}

int main(){
	Car c1;
	c1.getdata();
	c1.showdata();
}