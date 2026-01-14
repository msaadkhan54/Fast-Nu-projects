#include<stdio.h>
int main(){
	int i,j,arr[2][2];
	printf("Enter matrix elements:\n");
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
		   printf("for row %d and column %d:",i+1,j+1);
		   scanf("%d", &arr[i][j]);	
		}
	}
	int max=arr[0][0];
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
		   	if(arr[i][j]>max)
		   	max=arr[i][j];
		}
	}
	printf("The maximum element is %d",max);
}
