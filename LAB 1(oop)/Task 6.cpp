#include<iostream>
using namespace std;
int main(){
	int sum=0,num,i;
	cout<<"Enter number :";
	cin>>num;
	for(i=1;i<num;i++){
		if(num%i==0){
			sum+=i;
		}
	}
	if(sum==num){
		cout<<"The number "<<num<<" is a perfect number.";
	}
	else{
		cout<<"The number "<<num<<" is NOT a perfect number.";
	}
}
