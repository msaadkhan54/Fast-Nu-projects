#include <iostream>
using namespace std;
class Subject{
	private:
		string name;
	public:
		Subject(string n):name(n){}
		string get_name(){
			return name;
		}	
};
class Professor{
	private:
		string name;
		Subject* subjects[10];
		int count;
	public:
		Professor(string n):name(n),count(0) {}
		void addSubject(Subject* x){
			if(count>=10){
				cout<<"Can't add any more subjects"<<endl;
				return;
			}
			subjects[count++] = x;
		}
		void display(){
			cout<<"Teacher: "<<name<<endl;
			for(int i=0;i<count;i++){
				cout<<"-"<<subjects[i]->get_name()<<endl;
			}
		}	
};
int main(){
	Subject a("Calculus"),b("Multivariable Calculus""Digital logic Design"),c("Digital logic Design");
	Professor x("Mr Saad Khan");
	x.addSubject(&a);
	x.addSubject(&b);
	x.addSubject(&c);
	x.display();
}
