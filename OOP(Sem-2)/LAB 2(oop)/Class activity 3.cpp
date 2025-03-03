#include<iostream>
using namespace std;
int main(){
	int *ptr=new int;
	*ptr=7;
	int *ptr1=new int[5];
	for(int i=0;i<5;i++){
		ptr1[i]=i*2;
	}
	
	cout <<"Value at *ptr: "<<*ptr<<endl;
	cout<<"Array values"<<endl;
	for(int i=0;i<5;i++){
		cout<<ptr1[i]<<" ";
	}
}
