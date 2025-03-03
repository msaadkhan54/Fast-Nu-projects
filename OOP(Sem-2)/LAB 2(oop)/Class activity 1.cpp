#include<iostream>
using namespace std;

int main(){

int *ptr=new int;
*ptr= 42;

int size=5;
int *arr=new int[size];
for(int i=0;i<size;i++){
	arr[i]=i+1;
}

for(int i=0;i<size;i++){
	cout <<arr[i]<<endl;
}

delete ptr;
delete[] arr;
ptr=NULL;
arr=NULL;
cout <<*arr<<endl;
cout<<*ptr;
}
