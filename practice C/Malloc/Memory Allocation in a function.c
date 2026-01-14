#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void *function(char *arr){
	int i;
	char c;
	int len1=strlen(arr);
	char *ptr=(char*)malloc(len1*sizeof(char));
	
	if(ptr==NULL)
	printf("Error in Memory Allocation");
	for(i=0;i<len1;i++)
	{ptr[i]=arr[i];}
	ptr=(char*)realloc(ptr,(len1+1)*sizeof(char));
	do{
		char c;
		i=0;
	    scanf("%c",&c);
	    if(c=='Q')
	    break;
	    ptr[len1+i]=c;
	    i++;
	    ptr=(char*)realloc(ptr,(len1+i+1)*sizeof(char));
	}while(1);
	ptr[len1+i-1]='\0';
    for(i=0;i<len1;i++){
    	printf("%c",arr[i]);
	}
	printf("\n\n");
	int len2=strlen(ptr);
	for(i=0;i<(len1+len2);i++){
		printf("%c",ptr[i]);
	}
	free(ptr);
}

int main(){
	char arr[]="Hello";
	function(arr);	
}

