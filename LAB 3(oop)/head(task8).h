#ifndef head(task8)_h
#define head(task8)_h

#include<iostream>
#include<string>
using namespace std;
class Product{
 	public:
 	string productName;
 	float price;
 	int stock;
 	float discount;
 	
 	Product(string productName,float price,int stock,float discount){
 		this->productName=productName;
 		this->price=price;
 		this->stock=stock;
 		this->discount=discount;
	 }
 	void display(){
 		cout<<"The name : "<<productName<<endl;
 		cout<<"The price : $"<<price<<endl;
 		cout<<"The stock : "<<stock<<endl;
 		cout<<"The discount : "<<discount<<endl<<endl;
	}
	
	void applyDiscount();
	
	void updateStock(int num);
};
#endif
