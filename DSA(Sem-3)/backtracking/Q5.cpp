#include<iostream>
using namespace std;

bool combination(int *arr,int *check,int idx,int sum,int target,int start){
	if(sum==target){
		for(int i=0;i<10;i++){
			if(check[i]!=-1){
				cout<<check[i]<<" ";
			}
		}
		cout<<endl;
		return true;
	}
	
	for(int i=start;i<10;i++){
		if(sum+arr[i]<=target){
			check[idx]=arr[i];
			combination(arr,check,idx+1,sum+arr[i],target,i+1);
			check[idx]=-1;
		}
	}
	return false;
}

int main(){
	int arr[10]={12,1,2,5,74,66,22,33,87,13};
	int check[10];
	for(int i=0;i<10;i++)check[i]=-1;
	combination(arr,check,0,0,79,0);
}
