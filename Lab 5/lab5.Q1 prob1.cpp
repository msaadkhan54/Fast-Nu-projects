#include<stdio.h>
int main(){
	int age;
	printf("Enter age.\n");
	scanf("%d", &age);
	if(age>0){
		if(age<=12)
		printf("You are a child");
		else if(age<=19)
		printf("You are teenager");
		else if(age<=40)
		printf("You are adult");
		else printf("You are senior");
	}
	else printf("Invalid age");
}
