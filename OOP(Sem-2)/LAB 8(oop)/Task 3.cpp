#include<iostream>
#include<cstring>
using namespace std;
class Doctor;
class Patient{
	string name;
	int age;
	string MedicalHistory;
	public:
		Patient(string n,int a,string m):name(n),age(a),MedicalHistory(m){}
		friend Doctor;
};

class Doctor{
	public:
		void update(Patient &p1){
			cout<<"Enter name: ";
			cin>>p1.name;
			cout<<"Enter age: ";
			cin>>p1.age;
			cout<<"Enter Medical History: ";
			cin>>p1.MedicalHistory;
			cout<<"Successfully Updated"<<endl;
		}
		void display(Patient &p1){
			cout<<"Name: "<<p1.name<<" | "<<"Age: "<<p1.age<<" | Medical History: "<<p1.MedicalHistory<<endl;
		}
};
int main(){
	Patient pp("Jacob",23,"Diareha");
	Doctor d1;
	d1.display(pp);
	d1.update(pp);
	d1.display(pp);
}

