#include<iostream>
using namespace std;
int main(){
	
	int arr[7]={1,3,2,5,3,7,6};
	
	if (arr[0]>arr[1]){
		cout << arr[0]<<endl;
	}
	if(arr[6]>arr[5]){
		cout<<arr[6]<<endl;
	}
	
	for(int i=0;i<7;i++){
		if(arr[i]>arr[i-1] && arr[i]>arr[i-2] && arr[i]>arr[i+1]){
			cout<<arr[i]<<endl;
		}
	}
}
