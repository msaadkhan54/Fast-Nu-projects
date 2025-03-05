#include<iostream>
using namespace std;

class Base{
	public:
	int i;
	int b;
		Base(int i,int b){
			this->i=i;
			this->b=b;
		}
};

class Derived: public Base{
	public:
		Derived(int i,int b):Base(i,b){
		}
		void showData(){
			cout<<"i= "<<i<<endl<<"b= "<<b;
		}
};

int main(){
	Derived d1(4,5);
	d1.showData();
}
