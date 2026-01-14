#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void sinkHeapify(int* arr,int i,int size){
	int largest=i;
	int left=2*i+1;
	int right=2*i+2;
	if(left<size && arr[largest]<arr[left])
	largest=left;
	if(right<size && arr[largest]<arr[right])
	largest=right;
		
	if(largest!=i){
		swap(arr[largest],arr[i]);
		sinkHeapify(arr,largest,size);
	}	
}

void maxHeapify(int *arr,int size){
	int lastIdx=size-1;
	int i=(lastIdx-1)/2;
	while(i>=0){
		int largest=i;
		int left=2*i+1;
		int right=2*i+2;
		if(left<size && arr[largest]<arr[left])
		largest=left;
		if(right<size && arr[largest]<arr[right])
		largest=right;
		
		if(largest!=i){
			swap(arr[largest],arr[i]);
			sinkHeapify(arr,largest,size);
		}
		i--;
	}
	cout<<"Max Heap:"<<endl;
	for(int i=0;i<size;i++){
		cout<<arr[i]<<" ";
	}
}

int main(){
	int arr[]={12,13,14,65,33,78,90};
	cout<<"Min Heap:"<<endl;
	for(int i=0;i<7;i++){
		cout<<arr[i]<<" ";
	}cout<<endl;
	maxHeapify(arr,7);
}
