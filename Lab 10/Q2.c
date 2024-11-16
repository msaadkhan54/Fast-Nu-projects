#include<stdio.h>
#include<string.h>
void reverse(int a,char *ar){
    if(a>=0)
    printf("%c", ar[a]);
    reverse(a-1,ar);
}
	
	
int main(){
	char name[20];
	fgets(name, 19, stdin);
	int lenght=strlen(name);
    reverse(lenght,name);
    return 0;
}