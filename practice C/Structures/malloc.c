#include<stdio.h>
#include<stdlib.h>
int main(){
	int i;
	int *ptr;
	ptr=(int*) malloc(4* sizeof(int));
	for(i=0;i<4;i++)
	{
		scanf("%d",(ptr+i));
	}
	for(i=0;i<4;i++)
	{
		printf("%d ",*(ptr +i));
	}
	printf("\n");
	*(ptr +4)=36;
	*(ptr +5)=54;
	ptr=realloc(ptr,6* sizeof(int));
		for(i=0;i<6;i++)
	{
		printf("%d ",*(ptr +i));
	}
	free(ptr);
}
