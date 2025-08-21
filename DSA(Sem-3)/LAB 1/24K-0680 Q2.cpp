#include<iostream>
using namespace std;

class Movie{
	string *name;
	int seats;
	public:
		Movie(){
			name= new string("unknown");
			seats=NULL;
		}
		Movie(string nam,int seat){
			name=new string(nam);
			seats=seat;
		}
		Movie(const Movie &obj){
			name=new string(*obj.name);
			seats=obj.seats;
		}
		~Movie(){
			delete name;
			name=NULL;
		}
		void set_name(string nam){
			*name=nam;
		}
		void print(){
			cout<<"Name: "<<*name<<endl;
			cout<<"Seats: "<<seats<<endl<<endl;
		}
};

int main(){
	Movie t1("ok",12);
	Movie t2(t1);
	Movie t3=t2;
	t3.set_name("sign");
	
	t2.print();
	t3.print();
	
}
