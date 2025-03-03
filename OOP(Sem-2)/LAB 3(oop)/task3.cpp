#include<iostream>
using namespace std;

class Calculator{
	public:
		int add(int a,int b){
			return a+b;
		}
		int substract(int a,int b){
			return a-b;
		}
		int multiply(int a,int b){
			return a*b;
		}
		int divide(int a,int b){
			return a/b;
		}
};

int main(){
	Calculator c;
	int num1,num2;
	
	cout<<"Enter num1:";
	cin>>num1;
	cout<<"Enter num2:";
	cin>>num2;
	
	cout<<"add:"<<c.add(num1,num2)<<endl;
	cout<<"subtraction:"<<c.substract(num1,num2)<<endl;
	cout<<"multiplication:"<<c.multiply(num1,num2)<<endl;
	cout<<"division:"<<c.divide(num1,num2)<<endl;
}
