#include<stdio.h>
int main(){
	int num1,num2;
	printf("Enter two numbers");
	scanf("%d%d", &num1,&num2);
	(num1>num2)?printf("The number %d is greater",num1):(num1<num2)?printf("The number %d is greater",num2):printf("Both are Equal");
	return 0;
}
