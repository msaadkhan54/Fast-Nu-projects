#include<iostream>
using namespace std;
void display(int arr[][2]){
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			cout<<arr[i][j] <<" ";
		}
		cout<<endl;
	}
}
int main(){
	int arr1[2][2]={2,3,4,5};
	int arr2[2][2]={1,2,3,4};
	int add[2][2]={0},sub[2][2]={0};
	int mult[2][2]={0};
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			add[i][j]=arr1[i][j]+arr2[i][j];
		}
	}
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			sub[i][j]=arr1[i][j]-arr2[i][j];
		}
	}
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			for(int k=0;k<2;k++){
				mult[i][j]+=arr1[i][k]*arr2[k][j];
			}
		}
	}
	cout<<"THE ADDITION IS:"<<endl;
	display(add);
	cout<<endl;
	cout<<"THE SUBTRACTION IS:"<<endl;
	display(sub);
	cout<<endl;
	cout<<"THE Multiplication IS:"<<endl;
	display(mult);
	cout<<endl;
}
