#include<stdio.h>
int main(){
	char alphabet;
	int i=1,j,k;
	while(i<=7)
	{   
	    k=1;
		while(k<i)
		{
			printf(" ");
			k++;
		}
		j=1;
		alphabet=65;
		while(j<=8-i)
		{
			printf("%c ",alphabet);
			j++;
			alphabet+=1;
		}
		i++;
		printf("\n");
	}
}
