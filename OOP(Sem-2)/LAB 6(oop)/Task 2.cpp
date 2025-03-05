#include<iostream>
using namespace std;

class Employee{
	public:
		string name;
		int id;
		float salary;
		Employee(string n,int i,float s):name(n),id(i),salary(s){}
		void displayEmp(){
			cout<<"Employee Name: "<<name<<endl;
			cout<<"Employee Id: "<<id<<endl;
			cout<<"Base Salary: $"<<salary<<endl<<endl;
		}
};

class Manager:public Employee{
	int bonus;
	public:
		Manager(string n,int i,float s,int b):bonus(b),Employee(n,i,s){}
		
		int calculate(){
			return bonus+salary;	
		}
		
		void display(){
			cout<<"Employee Name: "<<name<<endl;
			cout<<"Employee Id: "<<id<<endl;
			cout<<"Base Salary: $"<<salary<<endl;
			cout<<"Total Salary: $"<<calculate()<<endl;	
		}
};

int main(){
	Employee e1("Alice Johnson",101,50000);
	e1.displayEmp();
	Manager m1("Bob Smith",102,75000,10000);
	m1.display();
}
