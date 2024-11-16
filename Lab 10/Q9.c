#include<stdio.h>
void sort(int arr[],int size){
    int i;
	if(size==1)
	return;
	for(i=0;i<size-1;i++){
		int temp=arr[i];
		if(arr[i+1]<arr[i]){
			arr[i]=arr[i+1];
			arr[i+1]=temp;}
		}
		sort(arr,size-1);
		return;	
	}

int main(){
	int i;
	int arr[6]={1,6,8,2,4,5};
	int size=sizeof(arr)/sizeof(arr[0]);
	sort(arr,size);
	
	for(i=0;i<size;i++)
	{
		printf("%d ",arr[i]);
	}
}
