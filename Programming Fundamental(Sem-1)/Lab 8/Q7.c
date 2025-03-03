#include<stdio.h>
int main(){
	int arr[2][3][3]={
	{{1,2,3},{4,5,6},{7,8,9}},
	{{9,8,7},{6,5,4},{3,2,1}}
	};
	int result;
	for(int i=0;i<2;i++)
	{   
	    result=0;
		printf("The sum of sheet %d:",i+1);
		for(int j=0;j<3;j++)
		{
			for(int k=0;k<3;k++)
			{
				result=result+arr[i][j][k];
			}
		}
		printf("%d\n ",result);
	}
}

