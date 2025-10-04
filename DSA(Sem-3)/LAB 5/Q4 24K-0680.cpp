#include<iostream>
using namespace std;
int count=0;
void numInteger(int num){
	if(num<=0){
		return ;
	}
	count++;
	numInteger(num/10);
}

int main(){
	int integer;
	cout<<"Enter integer to calculate lenght: ";
	cin>>integer;
	numInteger(integer);
	cout<<count;
}
