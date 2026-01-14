#include<stdio.h>
int main(){
 int num1,num2,num3;
 printf("Enter three numbers\n");
 scanf("%d %d %d", &num1,&num2,&num3);
 if(num1>num2){
 	if(num1>num3)
 	printf("The %d is greatest",num1);}
 if(num2>num1){
 	if(num2>num3)
 	printf("The %d is greatest",num2);}
 if(num3>num1){
 	if(num3>num2)
 	printf("the %d is greatest",num3);
	 }
  else printf("All are equal");	 
	 	
 }


