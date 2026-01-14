#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void heapify(int* arr,int i,int size){
	int smallest=i;
	int left=2*i+1;
	int right=2*i+2;
	if(left<size && arr[smallest]>arr[left]){
		smallest=left;
	}
	if(right<size && arr[smallest]>arr[right]){
		smallest=right;
	}
	if(smallest!=i){
		swap(arr[smallest],arr[i]);
		heapify(arr,smallest,size);
	}
	
}

void arrange(int* arr,int size){
	int i=size-1;
	i=(i-1)/2;
	while(i>=0){
		int smallest=i;
		int left=2*i+1;
		int right=2*i+2;
		if(left<size && arr[smallest]>arr[left]){
			smallest=left;
		}
		if(right<size && arr[smallest]>arr[right]){
			smallest=right;
		}
		if(smallest!=i){
			swap(arr[smallest],arr[i]);
			heapify(arr,smallest,size);
		}
		i--;
	}
}



int main(){
	int arr[]={5,90,4,1,8,3,2,0};
	arrange(arr,8);
	for(int i=0;i<8;i++){
		cout<<arr[i]<<" ";
	}
}
