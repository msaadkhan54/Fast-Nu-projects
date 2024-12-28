#include<stdio.h>
int main(){
	int num,result=0,rem;
	printf("Enter number.\n");
	scanf("%d", &num);
while(num>0){
	rem=num%10;
	num=num/10;
	1result=result+rem;	
	if(result<10)
	printf("The current result is %d\n",result);
	}
	printf("The final result is %d",result);
}
