#include <iostream>
using namespace std;
class Battery{
	private:
		int capacity;
		string type;
	public:
		Battery(int c,string t):capacity(c),type(t) {}	
		int getCapacity(){
			return capacity;
		}
		string getType(){
			return type;
		}
}; 
class Smartphone{
	private:
		string brand;
		Battery x;
	public:
		Smartphone(string b,int c,string t):brand(b),x(c,t) {}
		void display(){
			cout<<"Smartphone Brand: "<<brand<<endl;
			cout<<"Battery: "<<x.getCapacity()<<"mAh"<<" | Type: "<<x.getType()<<endl;
		}	
};
int main(){
	Smartphone x("Samsung",5000,"Li-ion");
	x.display();
}
