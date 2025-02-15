#include<iostream>
using namespace std;

class Product{
	private:
		string name;
		double price;
		int *data;
	public:
		int value=9;
		Product(){
			cout<<"Default contructor is called"<<endl;
			name="unknown";
			price=0.0;
			data=&value;
		
		}
		
		Product(string name,double price,int value){
			cout<<"Parametrized constructor is called"<<endl;
			this->name=name;
			this->price=price;
			data=new int(value);
		}
		
		Product(Product &obj){
			name=obj.name;
			price=obj.price;
			data=new int(*obj.data);
		}
		
		void display(){
			cout<<"Name : "<<name<<endl;
			cout<<"Price : "<<price<<endl;
			cout<<"Data value : "<<*data<<endl;
		}
		~Product(){
			cout<<"Destructor is called"<<endl;
//			delete data;
		}
};

int main(){
	Product p1;
	p1.display();
	Product p2(p1);
	p2.display();
	Product p3("Soap",100.21,4);
	p3.display();
}
