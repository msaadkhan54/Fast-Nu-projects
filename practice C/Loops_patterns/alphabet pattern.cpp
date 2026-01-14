#include<stdio.h>
int main()
{
	char alphabet;
	int i,j,k;
	for(int i=0;i<7;i++)
	{
		alphabet=65;
		for(int k=1;k<7-i;k++)
		{
			printf(" ");
		}
		for(int j=0;j<=i;j++)
		{
			printf("%c ",alphabet);
			alphabet+=1;
		}
		printf("\n");
	}
	for(i=1;i<=6;i++)
	{
		for(j=0;j<i;j++)
		{
			printf(" ");
		}
		alphabet=65;
		for(k=0;k<=6-i;k++)
		{
			printf("%c ",alphabet);
			alphabet++;
		}
		printf("\n");
	}
}
