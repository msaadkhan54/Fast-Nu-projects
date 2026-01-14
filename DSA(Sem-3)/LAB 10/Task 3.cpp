#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int* mergeArray(int*arr1,int size1,int*arr2,int size2){
	int i=0,j=0;
	int* merge = new int[size1 + size2]; 
	int idx=0;
	while(i<size1 && j<size2){
		if(arr1[i]>arr2[j]){
			merge[idx]=arr2[j];
			j++;
			idx++;
		}
		else{
			merge[idx]=arr1[i];
			i++;
			idx++;
		}
	}
	while(i<size1){
		merge[idx]=arr1[i];
		i++;
		idx++;
	}
	while(j<size2){
		merge[idx]=arr2[j];
		j++;
		idx++;
	}
	return merge;
}

void sinkHeapify(int* arr,int i,int size){
	int smallest=i;
	int left=2*i+1;
	int right=2*i+2;
	if(left<size && arr[smallest]>arr[left])
	smallest=left;
	if(right<size && arr[smallest]>arr[right])
	smallest=right;
	if(smallest!=i){
	swap(arr[smallest],arr[i]);
	sinkHeapify(arr,smallest,size);
	}
}

void minHeapify(int* arr,int size){
	int lastIdx=size-1;
	int i=(lastIdx-1)/2;
	while(i>=0){
		int smallest=i;
		int left=2*i+1;
		int right=2*i+2;
		if(left<size && arr[smallest]>arr[left])
		smallest=left;
		if(right<size && arr[smallest]>arr[right])
		smallest=right;
		if(smallest!=i){
			swap(arr[smallest],arr[i]);
			sinkHeapify(arr,smallest,size);
		}
		i--;
	}
	cout<<"Min Heap Merged:"<<endl;
	for(int i=0;i<8;i++){
		cout<<arr[i]<<" ";
	}cout<<endl;
}

int main(){
	int arr1[3]={12,45,46};
	int arr2[5]={1,4,7,98,99};
	cout<<"MIN HEAP 1:"<<endl;
	for(int i=0;i<3;i++){
		cout<<arr1[i]<<" ";
	}
	cout<<endl;
	cout<<"MIN HEAP 2:"<<endl;
	for(int i=0;i<5;i++){
		cout<<arr2[i]<<" ";
	}
	cout<<endl;
	int* arr=mergeArray(arr1,3,arr2,5);
	minHeapify(arr,8);
	delete[] arr;
}
