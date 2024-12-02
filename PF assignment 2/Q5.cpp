#include<stdio.h>
int main(){
	int values[4],i,j;
	printf("Enter 4 values:\n");
	for(i=0;i<4;i++)
	{
		scanf("%d", &values[i]);
	}
	printf("Horizontal Histogram:\n");
	for(i=0;i<4;i++)
	{
		printf("value %d={ ",i+1);
		for(j=1;j<=values[i];j++)
		{
			printf("* ");
		}
		printf("}");
		printf("\n");
	}
	printf("Vertical Histogram:\n");
	int max=values[0];
	for(i=0;i<4;i++)
	{
        if(values[i]>max){
		max=values[i];
		int save=i;}	
	}
	for(i=max;i>0;i--)
	{
	    for(j=0;j<4;j++)	
	    {
	    	if(values[j]>=i)
	    	printf("* ");
	    	else printf("  ");
		}
		printf("\n");
	}
	for(i=0;i<4;i++)
	{
		printf("%d ",values[i]);
	}	
}
