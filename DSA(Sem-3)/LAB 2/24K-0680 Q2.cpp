#include<iostream>
using namespace std;
int main(){
	int *arr=new int[5];
	
	cout<<"Enter Quantity: "<<endl;
	for(int i=0;i<5;i++){
		cout<<"Item "<<i+1<<": ";
		cin>>arr[i];	
	}
	int input,size;
	cout<<"Enter the Item that is sold: ";
	cin>>input;
	cout<<"Enter the quantity: ";
	cin>>size;
	for(int i=0;i<5;i++){
		if(i==input-1){
			if(size<=arr[i]){
				arr[i]-=size;
				cout<<"Stock updated!"<<endl;
			}
			else{
				cout<<"No available stock"<<endl;
			}
		}
	}
	
	cout<<endl<<"Rest available stock: "<<endl;
	for(int i=0;i<5;i++){
		cout<<"Item "<<i+1<<" stock: "<<arr[i]<<endl;
	}
	delete[] arr;
}
