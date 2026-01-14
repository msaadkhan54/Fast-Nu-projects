#include<iostream>
using namespace std;

void merge(float* arr,int st,int mid,int end){
	int i=st;
	int j=mid+1;
	int n=end-st;
	float temp[n];
	int idx=0;
	while(i<=mid && j<=end){
		if(arr[i]<arr[j]){
			temp[idx]=arr[i];
			i++;	
		}
		else{
			temp[idx]=arr[j];
			j++;
		}
		idx++;
	}
	while(i<=mid){
		temp[idx]=arr[i];
			i++;
			idx++;
	}
	while(j<=end){
		temp[idx]=arr[j];
			j++;
			idx++;
	}
	
	for(int i=0;i<idx;i++){
		arr[i+st]=temp[i];
	}
	
}

void mergeSort(float* arr,int st,int end){
	if(st<end){
		int mid=st+(end-st)/2;
		mergeSort(arr,st,mid);
		mergeSort(arr,mid+1,end);
		merge(arr,st,mid,end);
	}
}

int main(){
	float arr[]={ 3.2, 3.9, 2.8, 3.5, 3.0};
	cout<<"Before Sorting: "<<endl;
	for(int i=0;i<5;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl<<endl;
	mergeSort(arr,0,4);
	cout<<"After Sorting: "<<endl;
	for(int i=0;i<5;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl<<endl;
}
