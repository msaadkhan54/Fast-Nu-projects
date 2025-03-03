#include<iostream>
#include<string>
using namespace std;

class Patient{
	string name;
	int age;
	string condition;
	public:
		Patient(string n="",int ag=0,string cond=""):name(n),age(ag),condition(cond){
		}
		void set_detail(){
			cout<<"    PATIENT"<<endl;
			cout<<"Enter name: ";
			cin>>name;
			cout<<"Enter age: ";
			cin>>age;
			cin.ignore();
			cout<<"Enter Medical condition: ";
			getline(cin,condition);
		}
		void get_detail(){
			cout<<"Name:"<<name<<",Age:"<<age<<",Condition:"<<condition<<endl;
		}
};

class Hospital{
	Patient p1[3];
	int i;
	public:
		Hospital(string n, int age, string condition) : p1{ Patient(n, age, condition) } {
        	i = 0; 
    	}
		void add_patient(){
			i++;
			p1[i].set_detail();
		}
		void displayPatient(){
			cout<<"Hospital Patient Records:"<<endl;
			for(int j=0;j<3;j++){
				p1[j].get_detail();
			}
		}
};

int main(){
	Hospital h1("Ali",14,"breathing issue");
	h1.add_patient();
	h1.add_patient();
	h1.displayPatient();
}
