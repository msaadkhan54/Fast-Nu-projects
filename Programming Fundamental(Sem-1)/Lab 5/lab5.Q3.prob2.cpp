#include<stdio.h>
int main(){
	int num;
	printf("Enter number");
	scanf("%d", &num);
	(num>0)?printf("The %d is positive",num):(num<0)?printf("The %d is negative",num):printf("The %d is zero.",num);
	return 0;
}
