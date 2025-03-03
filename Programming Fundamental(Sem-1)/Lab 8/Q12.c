#include<stdio.h>
int main()
{
	int i,j,k,row;
	printf("Enter the number of upper half rows you want.\n");
	scanf("%d", &row);
	for(i=1;i<row+1;i++)
	{
		for(j=row-i;j>0;j--)
		{
			printf(" ");
		}
		for(k=1;k<=i;k++)
		{
			printf("* ");
		}
		printf("\n");
	}
	for(i=1;i<row;i++)
	{
		for(j=0;j<i;j++)
		{
			printf(" ");
		}
		for(k=row-i;k>0;k--)
		{
			printf("* ");
		}
		printf("\n");
	}
}

