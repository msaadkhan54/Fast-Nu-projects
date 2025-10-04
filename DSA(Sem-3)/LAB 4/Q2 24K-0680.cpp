#include<iostream>
using namespace std;

int combSort(int *arr,int size){
	int n=size;
	int gap=n;
	bool sort=false;
	float shrink=1.3;
	
	while(gap>1 || sort){
		gap=int(gap/shrink);
		if(gap<1)
		{
			gap=1;
		}
		sort=false;
		int i=0;
		while(gap+i<n){
			if(arr[i]>arr[gap+i]){
				int temp=arr[i];
				arr[i]=arr[gap+i];
				arr[gap+i]=temp;
				sort=true;
			}
			i++;
		}
	}
}

int main(){
	int ticket[10]={76,23,12,87,34,21,90,44,58,10};
	combSort(ticket,10);
	cout<<"Cheapest Tickets are: "<<endl;
	for(int i=0;i<3;i++){
		cout<<ticket[i]<<" ";
	}
}
