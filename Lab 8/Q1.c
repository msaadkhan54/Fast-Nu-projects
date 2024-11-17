#include<stdio.h>
int main(){
	int choice;
	printf("enter the numbert of rows:");
	scanf("%d",&choice);
	for(int i=choice;i>0;i--)
	{
		for(int j=1;j<=i;j++)
		{
			printf("%d ",j);
		}
		printf("\n");
	}
}

