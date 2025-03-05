#include<iostream>
using namespace std;

class Person{
	public:
		string name;
		string contactInfo;
		Person(string n,string ci):name(n),contactInfo(ci){}
};

class BankEmployee{
	public:
		int id;
		string position;
		BankEmployee(int i,string p):id(i),position(p){}
};

class Customer: public Person{
	public:
		int accNo;
		float balance;
		Customer(int a,float b,string n,string c1):accNo(a),balance(b),Person(n,c1){}
	
};

class bankManager:public BankEmployee,public Customer{
	public:
		bankManager(string nam,string info,int i,string pos,int acc,float bal):BankEmployee(i,pos),
		Customer(acc,bal,nam,info){}
		void accManager(){
			cout<<"=== Bank Manager Details ==="<<endl;
			cout<<"Name: "<<name <<endl;
			cout<<"Contact: "<<contactInfo <<endl;
			cout<<"Employee Id: "<<id <<endl;
			cout<<"Position: "<<position <<endl;
			cout<<"Account Number (for internal transactions): "<<accNo<<endl;
			cout<<"Balance: $"<<balance<<endl<<endl;
//			cout<<""<< <<endl;
		}
		void transactions(float deposit,float withdrawn){
			cout<<"=== Transactions ==="<<endl;
			balance+=deposit;
			cout<<"Deposited $"<<deposit<<". New balance $"<<balance<<endl;
			balance-=withdrawn;
			cout<<"Withdrawn $"<<withdrawn<<". New balance $"<<balance<<endl;
			cout<<"Insuffient fund!"<<endl;
		}
};

int main(){
	bankManager m1("Alice Johnson","alice@email.com",1001,"Branch Manager",50001,10000);
	m1.accManager();
	m1.transactions(5000,3000);
}
