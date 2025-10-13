// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int digits(int arr[],int n){
    int largest=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>largest){
            largest=arr[i];
        }
    }
    int count=0;
    while(largest>0){
        largest/=10;
        count++;
    }
    return count;
}

void radixSort(int* arr,int n,int k){
	int mod=10;
	int idx=0;
	int div=1;
    for(int i=0;i<k;i++){ // loop on digits
    
        for(int j=0;j<10;j++){ // loop to check smallest 0-9
        
            for(int k=0;k<n;k++){ // it does swaps if smallest is matched
            	int val=(arr[k]/div)%mod;
                if(val==j){
                	int temp=arr[k];
                	arr[k]=arr[idx];
                	arr[idx]=temp;
                	idx++;
				}
            }
        }
        mod*=10;
        idx=0;
        div*=10;
    }
}


int main() {
    int arr[5]={12345,321,43,21,12};
    radixSort(arr,5,digits(arr,5));
    for(int i=0;i<5;i++){
    	cout<<arr[i]<<" ";
	}
    return 0;
}
