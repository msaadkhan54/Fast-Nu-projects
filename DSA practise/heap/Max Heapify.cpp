#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void heapify(int *arr,int i,int size){
            int largest=i;
            int left=(2*i)+(1);
            int right=(2*i)+2;

            if(left<size && arr[largest]<arr[left])
                largest=left;
            if(right<size && arr[largest]<arr[right])
                largest=right;

            swap(arr[i],arr[largest]);
            if(largest!=i){
                heapify(arr,largest,size);
            }
            else{
            	return;
			}
        }
void arrange(int * arr,int size){
	int last=size-1;
	int i=(last-1)/2;
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
			heapify(arr,largest,size);
		}
		i--;
	}
}
int main(){
    int arr[]={4,5,9,7,2,10,1,3};
    
	arrange(arr,8);
	for(int i=0;i<8;i++){
       	cout<<arr[i]<<" ";
	}
}
