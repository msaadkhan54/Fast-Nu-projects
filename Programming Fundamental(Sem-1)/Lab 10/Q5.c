#include<stdio.h>

void print(int *arr,int size){	
	if(size==0)
	{
	 return;	
	}
	else{
      printf("%d ",*(arr +size-1));
      print(arr,size-1);
	}
}

int main(){
	int arr[5]={1,2,3,4,5};
	int size=sizeof(arr)/sizeof(arr[0]);
	print(arr,size);
}
