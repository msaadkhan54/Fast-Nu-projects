#include<iostream>
using namespace std;

class Product{
	string name;
	double price;
	public:
		Product(string input,double amount){
			name=input;
			price=amount;
		}
		
		void addProduct(string productName,double productPrice){
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
	Product product;
	product.display();
	product.addProduct("Laptop",1200.0);
	product.updatePrice(1100.0);
	product.display();
}
