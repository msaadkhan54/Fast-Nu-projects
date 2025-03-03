#include<iostream>
#include<iomanip>
using namespace std;

struct product{
	string name;
	int id;
	float price;
	int quantity;
};

int main(){
	struct product p1;
	p1.name="Soap";
	p1.id=342;
	p1.price=100.98;
	p1.quantity=6;
	
	cout<<"The name is "<<p1.name<<endl;
	cout<<"The id :"<<p1.id<<endl;
	cout<<"The price :"<<p1.price<<endl;
	cout<<"The qauntity :"<<p1.quantity;
}