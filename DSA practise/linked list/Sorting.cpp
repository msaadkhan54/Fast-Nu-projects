#include<iostream>
using namespace std;

void bubbleSort(int *arr,int n){
	bool swapped=false;
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-1-i;j++){
			if(arr[j]>arr[j+1]){
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				swapped=true;
			}
		}
		if(!swapped){
			return;
		}
	}
}

void selectionSort(int *arr,int n){
	for(int i=0;i<n;i++){
		int min=i;
		for(int j=i+1;j<n;j++){
			if(arr[min]>arr[j]){
				min=j;
			}
		}
		int temp=arr[i];
		arr[i]=arr[min];
		arr[min]=temp;
	}
}

void insertionSort(int *arr,int n){
	for(int i=1;i<n;i++){
		int curr=arr[i];
		int prev=i-1;
		while(prev>=0 && arr[prev]>curr){
			arr[prev+1]=arr[prev];
			prev--;
		}
		arr[prev+1]=curr;
	}
}

int main(){
	int n;
	cout<<"Enter size of array: ";
	cin>>n;
	int *arr=new int[n];
	for(int i=0;i<n;i++){
		cout<<"array["<<i<<"]: ";
		cin>>arr[i];
	}
//	bubbleSort(arr,n);
	insertionSort(arr, n);
//	selectionSort(arr,n);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}
