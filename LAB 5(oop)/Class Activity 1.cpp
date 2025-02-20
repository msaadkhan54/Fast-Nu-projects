#include<iostream>
using namespace std;

class Account{
	public:
		int accno;
		string name;
		
		static float rateofinterest;
		
		Account(int accno,string name){
				this->accno=accno;
			this->name=name;
		}
		void display(){
			cout<< accno <<" " <<name <<" "<<rateofinterest<<endl;
		}
};

float Account::rateofinterest=6.5;

int main(){
	Account a1(3211,"Saad");
	Account a2(3323,"Ali");
	a1.display();
	a2.display();
}

