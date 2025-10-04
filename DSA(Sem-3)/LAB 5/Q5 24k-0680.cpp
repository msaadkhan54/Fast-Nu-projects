#include<iostream>
using namespace std;

int Fibonacci(int n){
	if(n==0 || n==1){
		return n;
	}
	return Fibonacci(n-1)+Fibonacci(n-2);
}

int main(){
	int term;
	cout<<"Enter the TERM NUMBER: ";
	cin>>term;
	cout<<"The NUmber in Fibonacci Series at index "
	<<term<<" is: "<<Fibonacci(term);
}
