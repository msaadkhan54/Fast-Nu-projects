#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int validate(const char *email){
	int i,lenght,index_at,index_dot,count1=0,count2=0,count=0;
	lenght=strlen(email);

	for(i=0;i<lenght;i++)
	{
		if(email[i]=='@')
		{count1++;
		index_at=i;}
		
		if(email[i]=='.')
		{count2++;
		 index_dot=i;	}
		 
		if(email[i]>='a' && email[i]<='z')
		count++;
	}
    if(count1!=1 || count2<1)return 0;
    if(index_at>index_dot)return 0;
    if(count==0)return 0;
	return 1;
}
int main(){
	int lenght,i=0;
	char email[50],ch;
	printf("Enter email:\n");
	char *ptr;
	ptr=(char*) malloc(1*sizeof(char));
	while((ch=getchar())!='\n')
	{
		email[i]=ch;
		*(ptr +i)=email[i];
		i++;
		*ptr=(char*) realloc(ptr,(1+i)*sizeof(char));
	}
	if(validate(email))
	printf("Valid Email\n");
	else
	printf("Invalid Email");
	free(ptr);
}
