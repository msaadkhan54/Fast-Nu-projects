#include<iostream>
#include"sum.h"
#include"sum1.cpp"

using namespace std;

int main(){
	int num1=3,num2=5;
	int sumVariable=sum(num1,num2);
	int twice=sumTwice(num1,num2);
	cout<<"The sum is "<<sumVariable<<endl;
	cout<<"The twice is "<<twice;
	
}