#include<stdio.h>
int main(){
	int i,j;
	int arr[5]={1,-2,-57,100000,5};
	int *ptr=arr;
	int low=*(arr +0);
	for(i=1;i<=5;i++)
	{
		if(*ptr<low)
		low=*ptr;
		ptr++;
	}
	printf("The lowest Value is %d", low);
}
