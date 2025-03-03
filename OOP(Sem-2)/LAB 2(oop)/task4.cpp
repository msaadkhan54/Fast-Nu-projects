#include<iostream>
using namespace std;

int main(){
	int *ptr=new int[5];
	
	for(int i=0;i<5;i++){
		cout<<"Enter age for person "<<i+1<<" :";
		cin>>ptr[i];
	}
	cout<<endl<<endl;
	
	for(int i=0;i<5;i++){
		cout<<"The age for person "<<i+1<<" is "<<ptr[i]<<endl;
		
	}
	delete[] ptr;
}