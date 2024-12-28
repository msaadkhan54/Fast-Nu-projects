#include<stdio.h>
int main(){
	int num,rem1,rem2;
	printf("Enter number.\n");
	scanf("%d", &num);
	rem1=num%5;
	rem2=num%3;
	if(rem1==0 && rem2==0)
	printf("The number is both divisible by 5 and 3");
	else printf("The number is not divible by both");
}
