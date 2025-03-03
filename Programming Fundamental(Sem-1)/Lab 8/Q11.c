#include<stdio.h>
int main(){
	int arr1[2][2]={{2,3},{6,7}};
	int arr2[2][2]={{5,4},{8,9}};
	int result[2][2];
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			result[i][j]=arr1[i][j]*arr2[i][j];
			printf("The result for row %d and column %d is: %d\n",i+1,j+1,result[i][j]);
		}
	}
}

