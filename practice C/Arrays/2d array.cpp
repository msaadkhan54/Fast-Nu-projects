#include<stdio.h>
int main(){
	 int arr[4][4]={{1,1,1,1},{2,2,2,0},{3,3,0,0},{4,0,0,0}},count1=0,sum=0;
	 for(int i=0;i<4;i++)
	 {
	 	for(int j=0;j<=3-i;j++)
	 	{
	 		if(arr[0][j]!=0 || (arr[1][j]!=0 ) || (arr[2][j]!=0 ) || arr[3][j]!=0)
	 		{
	 			count1++;
				 sum=sum+arr[i][j]; 
			 }                
		}
	 }
	 printf(" sum is %d\n",sum);
	 if(count1==10)
	 printf("The matrix is upper triangular\n");
	 else printf("It is not a upper triangular .");
	 return 0;
}
