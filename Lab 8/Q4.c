#include<stdio.h>
int main(){
	int arr[3][3]={{1,2,3},{4,5,6},{7,8,9}};
	int temp=0;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<1;j++)
		{
			temp=arr[i][j];
			arr[i][j]=arr[i][j+2];
			arr[i][j+2]=temp;
		}
	}
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
}
