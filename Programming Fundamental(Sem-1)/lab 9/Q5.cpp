#include<stdio.h>
int main(){
	int arr1[3][2]={3,2,1,5,4,6};
	int arr2[3][2]={43,2,5,31,76,3};
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<2;j++)
		{
			*(*(arr1 +i) +j);
			for(int k=0;k<3;k++)
			{
				for(int l=0;l<2;l++)
				{
					if(*(*(arr1 +i) +j) == *(*(arr2 +k) +l)){
					printf("The element is %d.\nThe element are same at row %d of 'aar1' and column %d of 'arr1'\n",arr1[i][j],i+1,j+1);
					printf("The element are same at row %d of 'aar2' and column %d of 'arr2'\n\n",k+1,l+1);}
				}
			}
		}
	}
}
