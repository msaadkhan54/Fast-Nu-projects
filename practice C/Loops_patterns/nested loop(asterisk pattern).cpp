#include<stdio.h>
int main()
{
	for(int i=0;i<7;i++)
	{
		for(int j=0;j<i;j++)
		{
			printf(" ");
		}
		for(int k=0;k<7-i;k++)
		{
			printf("* ");
		}
		printf("\n");
	}
}
