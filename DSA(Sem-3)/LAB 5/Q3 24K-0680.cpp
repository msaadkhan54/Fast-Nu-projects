#include<iostream>
using namespace std;

void reverseArray(float *arr,int size){
	cout<<"The element ["<<size-1<<"] is: "<<arr[size-1]<<endl;
	if(size-1>0){
		reverseArray(arr,size-1);
	}	
}

int main(){
	int n;
	cout<<"Enter the size of array: ";
	cin>>n;
	float *arr=new float[n];
	cout<<"Enter Elements: "<<endl;
	for(int i=0;i<n;i++){
		cout<<"array["<<i<<"]: ";
		cin>>arr[i];
	}
	cout<<endl<<"FORWARD printing: "<<endl;
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl<<endl<<"REVERSE printing: "<<endl;
	reverseArray(arr,n);
}
