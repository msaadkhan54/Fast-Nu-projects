#include<iostream>
using namespace std;
int getDigits(int* arr,int n){
	int max=-1;
	for(int i=0;i<n;i++){
		if(arr[i]>max){
			max=arr[i];
		}
	}
	int count=0;
	while(max>0){
		max/=10;
		count++;
	}
	return count;
}

void count(int*arr,int n,int divi){
    int count1[10]={0};
    for(int i=0;i<n;i++){
        count1[(arr[i]/divi)%10]++;
    }
    
    for(int i=1;i<10;i++){
        count1[i]+=count1[i-1];
    }
    
    int temp[n];
    for(int i=n-1;i>=0;i--){
        temp[--count1[(arr[i]/divi)%10]]=arr[i];
    }
    
    for(int i=0;i<n;i++){
        arr[i]=temp[i];
    }
}


void RadixSort(int* arr,int n){
	int digits=getDigits(arr,n);
	int divi=1;
	for(int i=0;i<digits;i++){
	    count(arr,n,divi);
	    divi*=10;
	}
}

int main(){
	int arr[5]={123,43332,42,43,57};
	cout<<"Before Sorting: ";
	for(int i=0;i<5;i++){
	    cout<<arr[i]<<" ";
	}
	RadixSort(arr,5);
	cout<<endl<<endl<<"After Sorting: ";
	for(int i=0;i<5;i++){
	    cout<<arr[i]<<" ";
	}
}
