#include<stdio.h>
int main(){
	int prime=1,range,i;
	printf("Enter the range :");
	scanf("%d", &range);
	printf("The prime numbers are:\n");
	while(prime<=range)
	{
		i=2;
		printf("%d ",prime);
		prime=prime+i;
	}
}

