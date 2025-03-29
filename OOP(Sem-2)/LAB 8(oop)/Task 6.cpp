#include<iostream>
using namespace std;
class Payroll;
class HR;

class Employee{
	string name;
	int salary;
	int workHours;
	public:
		Employee(string n,int s,int w):name(n),salary(s),workHours(w){}
		friend HR;
		friend Payroll;
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
		friend Payroll;
};

class Payroll{
	public:
		void finalSalary(Employee e1,HR &h1){
			cout<<"Before deduction or increment the salary was "<<h1.ModifiedSalary<<endl;
			if(e1.workHours<9){
				h1.ModifiedSalary-=1000;
			}
			else {
				h1.ModifiedSalary+=2000;
			}
			cout<<"After deduction or increment the salary is "<<h1.ModifiedSalary<<endl;
		}
};

int main(){
	Employee e1("Saad",40000,12);
	HR h1;
	h1.updateSalary(e1);
	Payroll p1;
	p1.finalSalary(e1,h1);
}
