#include<stdio.h>
#include<string.h>
void reversed(char *arr,int len){
	char temp;
	for(int i=0;i<len/2;i++)
	{
		temp=*(arr +i);
		*(arr +i)=*(arr +(len-i-1));
		*(arr +(len-i-1))=temp;
	}
}
int main(){
	char str[100];
	printf("Enter Text.\n");
	gets(str);
	int lenght=strlen(str);
	reversed(str,lenght);
	printf("The reversed string is:\n");
	printf("'%s'",str);
}
