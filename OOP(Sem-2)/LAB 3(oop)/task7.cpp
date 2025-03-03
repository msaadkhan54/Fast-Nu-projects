#include<iostream>
using namespace std;
class ATM{
	public:
	string accountHolderName;
	long int accountNumber;
	double balance;
	ATM(string accountHolderName,long int accountNumber,double balance){
		this->accountHolderName=accountHolderName;
		this->accountNumber=accountNumber;
		this->balance=balance;
	}
	void checkBalance(){
		cout<<"The current balance is "<<balance<<endl;
	}
	void deposit(){
		double deposit1;
		cout<<"Enter the money to be deposited : ";
		cin>>deposit1;
		balance+=deposit1;
	}
	void withdrawMoney(){
		int amount;
		cout<<"Enter the amount : ";
		cin>>amount;
		if(amount<balance){
			balance-=amount;
			cout<<"The amount '"<<amount<<"' has been withdrawed"<<endl;
		}
		else{
			cout<<"insuffient balance :( ";
		}
	}
	
	void displayMenu(){
		int ch;
		cout<<"1:View Balance"<<endl;
		cout<<"2:Deposit"<<endl;
		cout<<"3:Withdraw Money"<<endl;
		cout<<"Enter : ";
		cin>>ch;
		if(ch==1){
			checkBalance();
		}
		else if(ch==2){
			deposit();
		}
		else if (ch==3){
			withdrawMoney();
		}
	}
};

int main(){
	ATM a1("Saad",5543534543,435643.76);
	a1.displayMenu();
}

