#include<iostream>
using namespace std;

void selectionSort(int *arr,int n){
	int large;
	for(int i=0;i<n;i++){
		int max=i;
		for(int j=i+1;j<n;j++){
			if(arr[max]<arr[j]){
				max=j;
			}
		}
		int temp=arr[i];
		arr[i]=arr[max];
		arr[max]=temp;
	}
}

void linearSearch(int arr[],int n){
	int input,start,end;
	cout<<"Enter the Salary to search: $";
	cin>>input;
	bool found=false;
	for(int i=0;i<n;i++){
		if(arr[i]==input){
			found=true;
			start=i;
			if(found){
				for(int j=i;j<n && arr[j]==input;j++){
					end=j;
				}
				break;
			}
		}
	}
	if(end-start<=1){
		cout<<"Salary $"<<input<<" is FOUND!"<<endl;
	}
	else{
		cout<<"First occurence on INDEX: "<<start<<" and last occurence on INDEX "<<end<<" hence FOUND!"<<endl;
	}
}

int main(){
	int arr[9];
	for(int i=0;i<9;i++){
		cout<<"Enter arr["<<i<<"]: ";
		cin>>arr[i];
	}
	selectionSort(arr,9);
	cout<<"DECENDING order: "<<endl;
	for(int i=0;i<9;i++){
		cout<<arr[i]<<" ";
	}
	linearSearch(arr,9);
}
