#include<stdio.h>
int main(){
	int start,end,remainder,countOdd=1,i,a,b;
	printf("Enter starting range from:");
	scanf("%d",&start);
	printf("Enter ending range till:");
	scanf("%d",&end);
	a=start;
	b=start;
	while(i<=end)
	{  	i=a;
	    countOdd=1;
	    while(countOdd<=5)
	    {   
		    remainder=i%2;
		    if(remainder!=0)
		    {
			printf("%d,",i);
			countOdd++;
	     	}
	     	i++;
	    }
	    a=i;
	    int j;
	    for(j=b;j<=end;j++)
	    {   remainder=j%2;
	    	if(remainder==0)
	    	{
	    		printf("%d,",j);
	    		b=j+1;
	    		break;
			}
		}
	 i=a;	
	}
	
}
