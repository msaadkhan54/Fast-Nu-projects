#include<stdio.h>
int main(){
	int num,rem;
	printf("Enter number.\n");
	scanf("%d", &num);
	if(num==0)
	printf("The number is zero");
	else if(num>0){
		printf("The number is positive\n");
	    rem=num%2;
	    if(rem==0)
	    printf("The number is even");
	    else printf("The number is odd");
	}
	else printf("The number is negative");
}
