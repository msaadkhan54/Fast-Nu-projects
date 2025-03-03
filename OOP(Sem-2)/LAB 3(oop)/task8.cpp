#include<iostream>
#include"head(task8).h""
using namespace std;

void Product::applyDiscount(){
		price=price*(1-discount);
	}
void Product::updateStock(int num){
		stock=stock-num;
	}

int main(){
	int sold;
	Product p1("soap",87.54,45,0.6);
	p1.display();
	p1.applyDiscount();
	cout<<"Enter number of product sold : ";
	cin>>sold;
	p1.updateStock(sold);
	p1.display();
	
}
