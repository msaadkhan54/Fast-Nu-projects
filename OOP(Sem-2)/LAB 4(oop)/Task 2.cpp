#include<iostream>
using namespace std;

class Student{
	string name;
	int rollNumber;
	double marks;
	
	public:
		Student(){
			name="Ali Ahmed";
			rollNumber=101;
			marks=85.5;
		}
		void displayInfo(){
			cout<<"Student Registered: "<<name<<"(Roll#"<<rollNumber<<")"<<endl;
			
			cout<<"Name: "<<name<<" | Roll Number: "<<rollNumber<<" | Marks: "<<marks<<"%"<<endl;
		}
		~Student(){
			cout<<"Student profile deleted: "<<name<<endl;
		}
};

int main(){
	Student s1;
	s1.displayInfo();
}
