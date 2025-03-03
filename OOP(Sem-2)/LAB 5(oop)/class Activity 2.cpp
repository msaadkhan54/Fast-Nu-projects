#include<iostream>
using namespace std;

class Bank{
	string accountHolder;
	double balance;
	static double totalBalance;
	public:
		Bank(string name,double initialBalance): accountHolder(name),balance(initialBalance){
			totalBalance+=initialBalance;
		}
		
		void deposit(double amount){
			balance+=amount;
			totalBalance+=amount;
			cout<<"Deposited "<<amount<<" into "<<accountHolder<<"'s account."<<endl;
		}
		
		void withdraw(double amount){
			if(amount>balance){
				cout<<"Insuffient balance in "<<accountHolder<<" account."<<endl;
			}
			else{
				balance-=amount;
				totalBalance-=amount;
				cout<<"Withdraw "<<amount<<" from "<< accountHolder <<" account "<<endl;
			}
		}
		
		static double getTotalbal(){
			return totalBalance;
		}
		
		void display(){
			cout<<"Account holder "<<accountHolder<<",Balance: "<<balance<<endl;
		}
};

double Bank:: totalBalance=0;

int main(){
	Bank b1("Saad",323);
	Bank b2("Ali",4344);
	cout<<"Initial Total Balance: "<<Bank::getTotalbal()<<endl;
	b1.deposit(500);
	b2.withdraw(1000);
	cout<<"Account Details: "<<endl;
	b1.display();
	b2.display();
	cout << "Updated Total Balance: "<<Bank::getTotalbal()<<endl;
	return 0;
}

