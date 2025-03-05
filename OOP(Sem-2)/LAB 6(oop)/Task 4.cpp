#include<iostream>
using namespace std;

class Person{
	public:
	string name;
	int age;
	Person(string n,int a):name(n),age(a){}
};

class Doctor:public Person{
	public:
		string specialization;
		Doctor(string s,string n,int a):specialization(s),Person(n,a){}
};

class Surgeon:public Doctor{
	public:
		int surgeryCount;
		Surgeon(int count,string s,string n,int a):surgeryCount(count),Doctor(s,n,a){}
		void display(){
			cout<<"  === Surgeon Details ==="<<endl;
			cout<<"Name: "<<name<<endl;
			cout<<"Age: "<<age<<endl;
			cout<<"Specialization: "<<specialization<<endl;
			cout<<"Surgeries Performed: "<<surgeryCount<<endl;
		}
};

int main(){
	Surgeon s1(250,"Cardiac Surgery","Dr. John Smith",45);
	s1.display();
}

