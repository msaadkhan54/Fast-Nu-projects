#include<iostream>
#include<unordered_map>
using namespace std;

void temp(int* arr,int n,int k){
	unordered_map<int,int> freq;
	for(int i=0;i<n;i++){
		if(freq.find(arr[i])!=freq.end()){
			freq[arr[i]]++;
		}
		else{
			freq[arr[i]]=1;
		}
	}
	int newArr[2];
	for(int i=0;i<k;i++){
		int largest=freq[arr[0]];
		for(int j=1;j<n;j++){
			if(freq[arr[j]]>freq[largest]){
				largest=arr[j];
			}
			else if(freq[arr[j]]==freq[largest]){
				if(arr[j]>largest){
					largest=arr[j];
				}
			}
		}
		freq[largest]=-1;
		newArr[i]=largest;
	}
	cout<<"Top K("<<k<<") elements are: ";
	for(int i=0;i<k;i++){
		cout<<newArr[i]<<" ";
	}
}

int main(){
	cout<<"Original Array : "<<endl;
	int arr[]={1,1,1,2,2,3,3,3,3,4,4,4};
	for(int i=0;i<12;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	temp(arr,12,2);
}
