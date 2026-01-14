#include<iostream>
using namespace std;

void shellSort(int *arr,int size){
	int gap,j,k,i,n=size;
	for( gap=n/2;gap>0;gap/=2){
		
		for( i=gap;i<n;i++){
			int temp=arr[i];
			for(j=i;j>=gap &&arr[j-gap]>temp;j-=gap){
				arr[j]=arr[j-gap];
			}
			arr[j]=temp;
		}
	}
	for( k=0;k<n;k++){
		cout<<arr[k]<<" ";
	}
}

int main(){
	int arr[8]={5,7,3,11,43,1,4,23};
	shellSort(arr,8);
}
