#include<iostream>
using namespace std;

class Product{
	string name;
	double price;
	public:
		Product(){
			name="unknown";
			price=0.0;
		}
		
		Product(string name,double price){
			this->name=name;
			this->price=price;
			cout<<"Product added: "<<name<<"- $"<<price<<endl;
		}	
	

		void updatePrice(double newPrice){
			price=newPrice;
			cout<<"Update price of "<<name<<"is $"<<price<<endl;
		}
		void display(){
			cout<<endl<<"Product: "<<name<<", price: $"<<price<<endl;
		}
};

int main(){
	Product defaultProduct;
	defaultProduct.display();
	
	Product product("Laptop",1200.0);;
	product.updatePrice(1100.0);
	product.display();
}
