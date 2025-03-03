#include<stdio.h>
int main(){
	int arr[2][2],tran[2][2],i,j;
	for(i=0;i<2;i++)
	{
		printf("Enter number in the matrix\n");
		for(j=0;j<2;j++)
		{
			printf("At row %d and column %d:",i+1,j+1);
			scanf("%d", &arr[i][j]);
		}
	}
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			printf("%d ",arr[j][i]);
		}
		printf("\n");
	}
}


