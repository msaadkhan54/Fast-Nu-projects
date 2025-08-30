#include<iostream>
using namespace std;
int main(){
	int n;
	cout<<"Enter number of trasactions done in a day: ";
	cin>>n;
	
	int *arr=new int[n];
	int sum=0;
	cout<<"Enter Trasactions: "<<endl;
	for(int i=0;i<n;i++){
		cout<<i+1<<": ";
		cin>>arr[i];
		sum+=arr[i];
	}
	cout<<endl<<"Total Balance: $"<<sum;
	delete[] arr;
	arr=NULL;
}
