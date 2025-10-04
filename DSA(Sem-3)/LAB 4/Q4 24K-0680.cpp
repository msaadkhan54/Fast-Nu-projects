#include<iostream>
using namespace std;

void bubbleSort(int *arr,int n){
	bool swapped;
	for(int i=0;i<n-1;i++){
		swapped=false;
		for(int j=0;j<n-1-i;j++){
			if(arr[j]>arr[j+1]){
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				swapped=true;
			}
		}
		if(!swapped) break;
	}
}

int main(){
	int size;
	cout<<"Enter number of books: ";
	cin>>size;
	int book[size];
	for(int i=0;i<size;i++){
		cout<<"Price of book "<<i+1<<": ";
		cin>>book[i];
	}
	bubbleSort(book,size);
	cout<<"Sorted Array: "<<endl;
	for(int i=0;i<size;i++){
		cout<<book[i]<<" ";
	}
}
