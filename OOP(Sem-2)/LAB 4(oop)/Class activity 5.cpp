#include<iostream>
using namespace std;

class Deep{
	public:
		int *data;
		
		Deep(int value){
			data=new int(value);
		}
		
		Deep(Deep &obj){
			data=new int(*obj.data); // New address of obj2.data is made and at that address the value of obj1.data is assigned
		}                           //  hence both pointers are having diffrent addresses
		void display(){
			cout<<"Data: "<<*data<<",Address: "<<data<<endl;
		}
};

int main(){
	Deep obj1(10);
	Deep obj2(obj1);
	
	obj1.display();
	obj2.display();
	delete obj1.data;
	delete obj2.data;
}
