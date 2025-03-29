#include<iostream>
using namespace std;
class InventoryManager;
class Product{
	string productName;
	float price;
	int stockQuantity;
	public:
		Product(string n,float p,int q):productName(n),price(p),stockQuantity(q){}
		friend InventoryManager;
};

class InventoryManager{
	public:
		void display(Product p1){
			cout<<"Product Name:"<<p1.productName<<" | Price:"<<p1.price<<" | Stock Quantity:"<<p1.stockQuantity<<endl<<endl;
		}
		void updateProduct(Product &p1){
			cout<<"-----------FOR PRODUCT: "<<p1.productName<<" -----------------"<<endl;
			cout<<"Enter price: ";
			cin>>p1.price;
			cout<<"Enter Stock Quantity: ";
			cin>>p1.stockQuantity;
		}
		void applyDiscount(Product &p1,float percentage){
			cout<<"Price before discount: "<<p1.price<<endl;
			p1.price=((100-percentage)/100)*p1.price;
			cout<<"Price after discount: "<<p1.price<<endl;
		}
};

int main(){
	Product p1("Shampoo",213.21,5);
	InventoryManager i1;
	i1.display(p1);
	i1.updateProduct(p1);
	i1.display(p1);
	i1.applyDiscount(p1,40);
}
