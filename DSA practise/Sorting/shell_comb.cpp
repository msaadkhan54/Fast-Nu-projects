#include<iostream>
// #include<bits/stdc++.h>
using namespace std;

void shellSort(int *arr,int n){
	int j;
	for(int gap=n/2;gap>0;gap/=2){
		for(int i=gap;i<n;i++){
			int temp=arr[i];
			for( j=i;j>=gap && arr[j-gap]>temp;j-=gap){
				arr[j]=arr[j-gap];
			}
			arr[j]=temp;
		}
	}
}

void combSort(int *arr,int n){
	bool swapped=true;
	int gap=n;
	while(gap!=1 || swapped){
		gap=int(gap)/1.3;
		if(gap<1){
			gap=1;
		}
		swapped=false;
		for (int i = 0; i < n-gap; i++)
		{
			if(arr[i]>arr[i+gap]){
				// swap(arr[i],arr[i+gap]);
				swapped=true;
			}
		}
		
	}
}

int main(){
	int arr[10]={32,54,12,98,54,23,55,89,7775,225};
	for(int i=0;i<10;i++){
        cout<<arr[i]<<" ";
    }
	shellSort(arr,10);
    cout<<endl<<"After Sorting: "<<endl;
    for(int i=0;i<10;i++){
        cout<<arr[i]<<" ";
    }
}
