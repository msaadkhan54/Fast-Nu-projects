#include <iostream>
#include <string>
using namespace std;
class student{
	string name;
	int rollno;
	int age;
	public:
		student(string n,int r,int a): name(n),rollno(r),age(a){}
		void displaystudent(){
			cout<<"name:"<<name<<endl<<"roll no:"<<rollno<<endl<<"age:"<<age<<endl;
		}
		
};
int main(){
	student A("akbar",3,20);
	A.displaystudent();
	return 0;
}
