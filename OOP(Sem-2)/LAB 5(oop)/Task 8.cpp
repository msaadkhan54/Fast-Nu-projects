#include <iostream>
using namespace std;
class LoanAccount{
	private:
		const int acc_no;
		double loan;
	public:
		LoanAccount(int a,double l): acc_no(a),loan(l) {}
		void display(){
			cout<<"Account No: "<<acc_no<<" | Loan Balance: "<<loan<<endl;
		}
		int getAccountNumber() const{
			return acc_no;
		}
		double getLoanBalance(){
			return loan;
		}	
		void applyPayment(double amount){
			loan -= amount;
			display();
		}
		void takeLoan(double amount){
			loan += amount;
			display();
		}
		
};
int main(){
	LoanAccount x(1001,5000);
	x.getAccountNumber();
	x.display();
	x.applyPayment(1000);
	x.takeLoan(2000);
}
