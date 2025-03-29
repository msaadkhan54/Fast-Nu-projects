#include<iostream>
using namespace std;
class Transaction;
class BankAccount{
	int accountNumber;
	int balance;
	public:
		BankAccount(int a,int b):accountNumber(a),balance(b){}
		friend Transaction;
};

class Transaction{
	public:
		void processTransaction(BankAccount &b){
			int amount;
			cout<<"Enter Withdrawl: ";
			cin>>amount;
			b.balance-=amount;
			cout<<"Final amount remaining is "<<b.balance;
		}
};

int main(){
	BankAccount b1(13231,32000);
	Transaction t1;
	t1.processTransaction(b1);
}
