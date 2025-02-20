#include <iostream>
using namespace std;
class employee{
public:
	string name;
	int id;
	employee(string empName, int empId) : name(empName), id(empId) {}
	void display() const {
		cout << "emloyee id: " << id << ", name: " << name << endl;
	}
};
class department{
	string deptName;
	employee* employees[10];
	int employeeCount = 0;
public:
	department(string name) : deptName(name){}

	void addEmployee(employee* emp){
		employees[employeeCount++] = emp;
	}

	void displayDepartment()const{
		cout << "department:" << deptName << endl << "employees:" << endl;
		for (int i = 0; i < employeeCount; i++) employees[i]->display();
	}
};
int main(){
	employee e1("babar azan", 8), e2("shaheen afridi", 16), e3("m.rizwan", 36);
	department dept("Software Engineering");
	dept.addEmployee(&e1);
	dept.addEmployee(&e2);
	dept.displayDepartment();
	cout << endl << "independent employee: " << endl;
	e3.display();
}
