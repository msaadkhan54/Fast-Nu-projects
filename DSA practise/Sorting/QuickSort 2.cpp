#include<iostream>
using namespace std;

int partition(int* arr,int st,int end){
	int pivot=end;
	st=st-1; // starting from -1 index and end starting from pivot idx
	while(1){
		while(arr[++st]<arr[pivot]){
			
		}
		
		while(arr[--end]>arr[pivot]){
		}
		if(st>=end){
			break;
		}
		else{
			int temp=arr[st];
			arr[st]=arr[end];
			arr[end]=temp;
		}
	};
	int num=arr[st];
	arr[st]=arr[pivot];
	arr[pivot]=num;
	return st;
}

void quickSort(int* arr,int st,int end){
	if(st<end){
		int pivotIdx=partition(arr,st,end);
		quickSort(arr,st,pivotIdx-1);
		quickSort(arr,pivotIdx+1,end);
	}
}

int main(){
	int arr[11] = {24, 2, 45, 20, 56, 75, 2, 56, 99, 53, 12};
	quickSort(arr,0,10);
	cout << "After sorting: ";
    for (int i = 0; i < 11; i++)
        cout << arr[i] << " ";
    cout << endl;
}
