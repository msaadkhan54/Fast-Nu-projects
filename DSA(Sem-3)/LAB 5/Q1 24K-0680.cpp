#include<iostream>
using namespace std;

int GCD(int num1,int num2){
	int rem=num1%num2;
	if(rem==0){
		return num2;
	}
	GCD(num2,rem);
}

int main(){
	int num1,num2;
	cout<<"Enter the two number to FIND GCD of them: "<<endl;
	cin>>num1>>num2;
	cout<<"The GCD of "<<num1<<" and "<<num2<<" is: "<<GCD(num1,num2);
	
}
