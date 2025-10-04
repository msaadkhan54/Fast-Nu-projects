#include<iostream>
using namespace std;

int factorial(int n){
	if(n==1){
		return 1;
	}
	return n*factorial(n-1);
}

int main(){
	int num;
	cout<<"Enter Number for having a FACTORIAL of it: ";
	cin>>num;
	cout<<"The FACTORIAL of NUMBER "<<num<<" is: "<<factorial(num);
}
