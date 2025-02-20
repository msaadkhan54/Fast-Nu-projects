#include <iostream>
using namespace std;

class EmployeeSalary{
	string name;
	double salary;
	public:
		void getEmployee(){
			cout<<"Enter name of Employee "<<": ";cin>>name;
			cout<<"Enter salary of Employee "<<": ";cin>>salary;
		}
		void display(){
			cout << "Employee: "<<name<<" | Salary: $"<<salary<<endl;
		}
};
int main(){
	EmployeeSalary e[3];
	for (int i=0;i<3;i++){
		e[i].getEmployee();
	}
	cout <<endl<< "Employee salary Records:"<<endl;
	for (int i=0;i<3;i++){
		e[i].display();
	}
	return 0;
}
