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
		
		
		Product(string productName,double productPrice){
			name=productName;
			price=productPrice;
			cout<<"Product added: "<<name<<"- $"<<price<<endl;
		}
		
		
		void updatePrice(double newPrice){
			price=newPrice;
			cout<<"Product added: "<<name<<"- $"<<price<<endl;
		}
		
		
		void display(){
			cout<<"Product: "<<name<<", price: $"<<price<<endl;
		}
		
};

int main(){
	Product defaultProduct;
	defaultProduct.display();
	
	Product product("Laptop",1200.0);;
	product.updatePrice(1100.0);
	product.display();
}
