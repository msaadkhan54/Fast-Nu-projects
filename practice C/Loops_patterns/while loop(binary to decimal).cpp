#include<stdio.h>
int main(){
	int binary,y,v=1,sum,x;
	printf("Enter binary number.\n");
	scanf(" %d", &binary);
	while(binary>=0)
	{
		y=binary%10;
		binary=binary/10;
		x=y*v;
		v=v*2;
		sum=sum+x;
	}
	printf("the sum is %d",sum);
}
