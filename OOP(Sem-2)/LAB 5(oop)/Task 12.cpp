#include <iostream>
using namespace std;
class Student{
	private:
		int id;
		string name;
		int grade;
	public:
		Student(int i,string n,int g):id(i),name(n),grade(g) {}
		int get_id(){
			return id;
		}
		string get_name(){
			return name;
		}
		int get_grade(){
			return grade;
		}
};
class Course{
	private:
		string title;
		Student* x[10];
		int count;
	public:
		Course(string t):title(t),count(0) {}
		void add_student(Student* z){
			if(count>=10){
				cout<<"Can't add any more students"<<endl;
				return;
			}
			x[count++] = z;
		}
		void display(){
			cout<<"Course: "<<title<<" - Student List:"<<endl;
			for(int i=0;i<count;i++){
				cout<<"ID: "<<x[i]->get_id()<<" | Name: "<<x[i]->get_name()<<" | Grade: "<<x[i]->get_grade()<<endl;
			}
		}	
};
int main(){
	Student x(1001,"Muhammad",85),y(1002,"Saad",90),z(1003,"Khan",95);
	Course a("Multi-Variable Calculus");
	a.add_student(&x);
	a.add_student(&y);
	a.add_student(&z);
	a.display();
}
