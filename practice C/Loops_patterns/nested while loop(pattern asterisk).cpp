#include<stdio.h>
int main(){
	int i=0,j,k;
	while(i<7)
	{
		j=0;
		while(j<i)
		{
			printf(" ");
			j++;
		}
		k=0;
		while(k<7-i)
		{
			printf("* ");
			k++;
		}
		printf("\n");
		i++;
	}
}
