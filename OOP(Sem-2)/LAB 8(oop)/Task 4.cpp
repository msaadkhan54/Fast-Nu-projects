#include<iostream>
using namespace std;
class HR;
class Manager;

class Employee{
	string name;
	int salary;
	public:
		Employee(string n,int s):name(n),salary(s){}
		friend HR;
};

class HR{
	int ModifiedSalary;
	public:
		void updateSalary(Employee &e1){
			cout<<"Current salary: "<<e1.salary<<endl;
			e1.salary*=30;
			ModifiedSalary=e1.salary;
			cout<<"Updated salry: "<<e1.salary<<endl;
		}
		friend Manager;
};

class Manager{
	public:
		void viewSalary(HR &h1){
			cout<<"Salary is "<<h1.ModifiedSalary;
		}
};

int main(){
	Employee e1("Saad",100000);
	HR h1;
	h1.updateSalary(e1);
	Manager m1;
	m1.viewSalary(h1);
}
