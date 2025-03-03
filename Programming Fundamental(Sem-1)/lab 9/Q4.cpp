#include<stdio.h>
void even_odd(int num){
	if(num%2==0)
	printf("The number '%d' is EVEN",num);
	else printf("The number '%d' is ODD",num);
}
int main(){
	int number;
	printf("Enter the number\n:");
	scanf("%d", &number);
	even_odd(number);
}
