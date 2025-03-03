#include<iostream>
using namespace std;
typedef struct person{
	string name;
	int citno;
	double salary;
}person;

int main(){
	person person1;
	person1.name="Jhone Doe";
	person1.citno=123432;
	person1.salary=234543.321;
	
	cout<<"Name: "<<person1.name<<endl;
	cout<<"City no: "<<person1.citno<<endl;
	cout<<"Salary: "<<person1.salary<<endl;
	
	
}