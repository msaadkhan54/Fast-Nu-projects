#include<iostream>
#include<iomanip>
using namespace std;

class Products{
	public:
		string name;
		float price;
		string brand;
		Products(string n,float p,string b):name(n),price(p),brand(b){}
		void displayPro(){
			cout<<"Product Name: "<<name<<endl;
			cout<<"Brand: "<<brand<<endl;
			cout<<"price: $"<<setprecision(4)<<price<<endl<<endl;
		}
};

class ElectronicProduct:public Products{
	int warrantyPeriod;
	public:
		ElectronicProduct(int w,string n,float p,string b):warrantyPeriod(w),Products(n,p,b){
		}
		void display(){
			cout<<"Product Name: "<<name<<endl;
			cout<<"Brand: "<<brand<<endl;
			cout<<"price: $"<<setprecision(4)<<price<<endl<<endl;
			cout<<"Warranty Period: "<<warrantyPeriod<<"months"<<endl;
		}
};

int main(){
	Products p1("BackPack",49.999,"Nike");
	p1.displayPro();
	ElectronicProduct e1(24,"BackPack",49.990,"Nike");
	e1.display();
}
