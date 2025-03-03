#include<iostream>
#include"pat(task9).h"
using namespace std;

void Patient::addDetail(){
	cout<<"enter name : ";
	cin>>name;
		
	cout<<"Enter age : ";
	cin>>age;
		
	cout<<"Enter diesease : ";
	cin>>diesease;
		
	cout<<"Enter room number : ";
	cin>>roomNum;
	}
	
void Patient::display(){
	cout<<"Name : "<<name<<endl;
	cout<<"age : "<<age<<endl;
	cout<<"Diesease : "<<diesease<<endl;
	cout<<"Room Number : "<<roomNum<<endl;
}

void Patient::update(int num){
	roomNum=num;
}

int main(){
	int room;
	Patient p1;
	p1.addDetail();
	p1.display();
	cout<<"Enter room : ";
	cin>>room;
	p1.update(room);
	p1.display();
}
