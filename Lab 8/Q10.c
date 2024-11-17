#include<stdio.h>
int main(){
	int arr[3][3]={{1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
     int max,low;
	 int low_index=0,j;   
	for(int i=0;i<3;i++)
	{
		low=arr[i][0];
		max=arr[0][i];
		for(int j=0;j<3;j++)
		{
			if(arr[i][j]<low)
			{
				//i use low_index to save the value of column number where there is the smallest number in a row
				low=arr[i][j];
				low_index=j;
			}
			if(arr[j][low_index]>max)
			{
				// Then the that column is checked if it has largest value and must match with the low.
				max=arr[j][low_index];
			}
		}
		if(low==max)
		{
			
			printf("The saddle point is :%d\n",max);
		}
	}
}

