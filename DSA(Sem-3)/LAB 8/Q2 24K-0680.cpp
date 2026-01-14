#include<iostream>
using namespace std;

int partition(int* arr,int left,int right){
	left=left-1;
	int pivot=right;
	while(1){
		while(arr[++left]<arr[pivot]){
		}
		while(arr[--right]>arr[pivot]){
		}
		if(left>=right){
			break;
		}
		else{
			int temp=arr[left];
			arr[left]=arr[right];
			arr[right]=temp;
		}
	}
	int num=arr[left];
	arr[left]=arr[pivot];
	arr[pivot]=num;
	return left;
}

void quickSort(int* arr,int left,int right){
	if(left<right){
		int pivotIdx=partition(arr,left,right);
		quickSort(arr,left,pivotIdx-1);
		quickSort(arr,pivotIdx+1,right);
	}
}

int main(){
	int arr[]={1200, 450, 2300, 800, 1500};
	cout<<"Before Sorting: "<<endl;
	for(int i=0;i<5;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl<<endl;
	quickSort(arr,0,4);
	cout<<"After Sorting: "<<endl;
	for(int i=0;i<5;i++){
		cout<<arr[i]<<" ";
	}
}
