#include<stdio.h>
#include<string.h>
int lighten(int ptr[8][8],int i,int j){
	*(*(ptr + i) + j)=*(*(ptr + i) + j)*1.1;
	if (*(*(ptr + i) + j) > 255)
        *(*(ptr + i) + j) = 255;
	if(*(*(ptr +i)+j)==255)
	return 1;
	else{
		return 0;
	}
}

void display(int ptr[][8],int row,int column){
	int i,j;
	for(i=0;i<row;i++)
	{
		for(j=0;j<column;j++)
		{
			printf("%4d",*(*(ptr +i)+j));
		}
		printf("\n");
	}
}
int main(){
	int i,j,flag;
	int arr[8][8];
	for(i=0;i<8;i++)
	{
		printf("Enter 8 elements for row %d\n",i+1);
		for(j=0;j<8;j++){
			do{
				scanf("%d",&arr[i][j]);
			}while(arr[i][j]<0 || arr[i][j]>255);
		}
		printf("\n");
	}
    
    for(i=0;i<8;i++)
    {
    	printf("For row %d:\n",i+1);
    	for(j=0;j<8;j++)
    	{
    		flag=0;
    		flag=lighten(arr,i,j);
    		if(flag==1)
    		printf("Thje image is BURNOUT at column %d\n",j+1);
		}
	}
	display(arr,8,8);
}
