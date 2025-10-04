#include<iostream>
using namespace std;

void printArray(int arr[]){
	for(int i=0;i<10;i++){
		cout<<arr[i]<<" ";
	}
}

void insertionSort(int *arr){
	for(int i=1;i<10;i++){
		int curr=i;
		int prev=i-1;
		while(prev>=0 && arr[prev]>arr[curr]){	
			arr[prev+1]=arr[prev];
			prev--;
		}
		arr[prev+1]=arr[curr];
	}
}

void BinarySearch(int arr[]){
	int choice;
	cout<<endl<<"Enter the score you want to find: ";
	cin>>choice;
	int left=0;
	int right=9;
	bool found=false;
	while(left<=right){
		int mid=left+(right-left)/2;
		if(arr[mid]==choice){
			cout<<"The RANK of student with score "<<choice<<" is: "<<mid;
			found=true;
			break;
		}
		else if(arr[mid]>choice){
			right=mid-1;
		}
		else if(arr[mid]<choice){
			left=mid+1;
		}
	}
	if(!found){
		cout<<"Score not FOUND"<<endl;
	}
}
int main(){
	int array[10]={12,43,86,41,32,54,90,36,17,32};
	insertionSort(array);
	cout<<"The sorted ARRAY :"<<endl;
	printArray(array);
	BinarySearch(array);
}
