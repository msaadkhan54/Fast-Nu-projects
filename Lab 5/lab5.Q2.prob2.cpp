#include<stdio.h>
 int main(){
 int age,choice;
 printf("Enter\n    1:if you are citizen of Pakistan\n    2:if you are not a citizen\n");
 scanf("%d", &choice);
 if(choice==1){
 	printf("Enter age.\n");
 	scanf("%d", &age);
 	if(age<18)
 	printf("You are not eligible for vote");
 	else printf("You are eligible for vote");
 }
 else printf("You cannot vote regardless of whatever the age is");
}
