#include<stdio.h>
int main(){
	int arr[2][3][2]={{12,43,54,65,71,98},{32,43,65,21,31,63}};
	int low=arr[0][0][0];
	int max=0;
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<3;j++)
		{
			for(int k=0;k<2;k++)
			{
				if(*(*(*(arr +i) +j) +k)>max)
				max=*(*(*(arr +i) +j) +k);
				if(*(*(*(arr +i) +j) +k)<low)
				low=*(*(*(arr +i) +j) +k);
			}
		}
	}
	printf("The minimum element is %d\n",low);
	printf("The maximum element is %d",max);
}
