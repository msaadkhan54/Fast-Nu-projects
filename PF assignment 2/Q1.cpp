#include<stdio.h>
int main()
{
	int arr[5],i,low2;
	printf("The value entered must be less than 999.\n");
	do
   	{  
	    for(i=0;i<5;i++)
	    {
	    	scanf("%d", &arr[i]);
	    	if(arr[i]>999)
	    	{	
		    printf("Incorrect value\nEnter again!\n");
	    	break;
			}
     	}
    }
    while(arr[i]>999);
	
	int low=arr[0];
	for(i=0;i<5;i++)
	{
		if(arr[i]<low)
		low=arr[i];
	}
	for(i=0;i<5;i++)
	{
		if(arr[i]!=low){
		low2=arr[i];
		break;}
	}
	for(i=0;i<5;i++)
	{
		if(arr[i]!=low){
			if(arr[i]<low2)
			low2=arr[i]; 
		}
	}
	printf("The second smallest value in an array : %d",low2);
}
