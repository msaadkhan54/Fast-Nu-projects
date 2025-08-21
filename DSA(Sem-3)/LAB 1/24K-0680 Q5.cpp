#include<iostream>
using namespace std;

class Teacher{
	string *name;
	string *subject;
	int experience;
	public:
		Teacher(string nam,string sub,int exp){
			name=new string(nam);
			subject=new string(sub);
			experience=exp;
		}
		~Teacher(){
			delete name;
			delete subject;
		}
		void display(){
			cout<<"Name: "<<*name<<endl;
			cout<<"Subject: "<<*subject<<endl;
			cout<<"Experience: "<<experience<<endl<<endl;
		}
		void set_name(string nam){
			*name=nam;
		}
};

class newTeacher{
	string *name;
	string *subject;
	int experience;
	public:
		newTeacher(string nam,string sub,int exp){
			name=new string(nam);
			subject=new string(sub);
			experience=exp;
		}
		~newTeacher(){
			delete name;
			delete subject;
		}
		void operator=(const newTeacher &obj){
			name=new string(*obj.name);
			subject=new string(*obj.subject);
			experience=obj.experience;
		}
		newTeacher(const newTeacher &obj){
			name=new string(*obj.name);
			subject=new string(*obj.subject);
			experience=obj.experience;
		}
		void display(){
			cout<<"Name: "<<*name<<endl;
			cout<<"Subject: "<<*subject<<endl;
			cout<<"Experience: "<<experience<<endl<<endl;
		}
		void set_name(string nam){
			*name=nam;
		}
};

int main(){
	cout<<"BEFORE RULE of 3"<<endl;
	Teacher t1("Aziz","DLD",7);
	Teacher t2(t1);
	t1.display();
	t2.display();
	t2.set_name("Ali");
	t1.display();
	t2.display();
	cout<<endl<<"BEFORE RULE of 3"<<endl;
	newTeacher nt1("Aziz","DLD",7);
	newTeacher nt2(nt1);
	nt1.display();
	nt2.display();
	nt2.set_name("Ali");
	nt1.display();
	nt2.display();
}
