#include<iostream>
using namespace std;

class Car{
//	public:
	string model;
	int year;
	                                        
	public:
	Car(string m,int y) : model(m),year(y){}
	
	void display(){
		cout<<"Car model : "<<model<<", Year : "<<year<<endl;
	}
};

int main(){
	Car mycar("Toyota",2022);
	mycar.display();
}