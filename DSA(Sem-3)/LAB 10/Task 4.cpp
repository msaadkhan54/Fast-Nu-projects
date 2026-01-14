#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void sinkHeapify(int* arr,int i,int size){
	int largest=i;
	int left=2*i+1;
	int right=2*i+2;
	if(left<size && arr[left]>arr[largest]){
		largest=left;
	}
	if(right<size && arr[right]>arr[largest]){
		largest=right;
	}
	if(largest!=i){
		swap(arr[largest],arr[i]);
		sinkHeapify(arr,largest,size);
	}
}

int deleteNode(int* arr,int size){
	arr[0]=arr[size-1];
	size--;
	sinkHeapify(arr,0,size);
	return size;
}



void swimMaxHeap(int* arr,int size){
	if(size==1){
		return;
	}
	int k=size-1;
	int i=(k-1)/2;
	while(i>=0){
		int largest=i;
		int left=2*i+1;
		int right=2*i+2;
		if(left<size && arr[left]>arr[largest]){
			largest=left;
		}
		if(right<size && arr[right]>arr[largest]){
			largest=right;
		}
		if(largest!=i){
			swap(arr[largest],arr[i]);
			sinkHeapify(arr,largest,size);
		}
		i--;
	}
}

void mergeMaxHeap(int* arr1,int size1,int* arr2,int size2){
	int cap=0;
	int* newHeap=new int[(size1+size2)];
	while(size1>0 && size2>0){
		if(arr1[0]>arr2[0]){
			newHeap[cap]=arr1[0];
			size1=deleteNode(arr1,size1);
			cap++;
			swimMaxHeap(newHeap,cap);
		}
		else{
			newHeap[cap]=arr2[0];
			size2=deleteNode(arr2,size2);
			cap++;
			swimMaxHeap(newHeap,cap);
		}	
	}
	while(size1){
		newHeap[cap]=arr1[0];
		size1=deleteNode(arr1,size1);
		cap++;
		swimMaxHeap(newHeap,cap);
		
	}
	while(size2>0){
		newHeap[cap]=arr2[0];
		size2=deleteNode(arr2,size2);
		cap++;
		swimMaxHeap(newHeap,cap);
		
	}
	
	for(int i=0;i<cap;i++){
		cout<<newHeap[i]<<" ";
	}
	delete[] newHeap;
	newHeap=NULL;
} 

int main(){
	int arr1[]={11,10,9,5,3,2};
	int arr2[]={43,21,32,12,6,17,16,1};
	mergeMaxHeap(arr1,6,arr2,8);	
}
