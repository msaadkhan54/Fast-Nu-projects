#include<stdio.h>
int main(){
	int totalSum=0,arr[4][2]={{1,2},{3,4},{5,6},{7,8}};
	int *ptr=&arr[0][0];
	for(int i=1;i<=8;i++)
	{
		totalSum+=*ptr;
		ptr++;
	}
	printf("I guessed the total sum would be 36\n");
	printf("Lests see the result now : %d",totalSum);
}
