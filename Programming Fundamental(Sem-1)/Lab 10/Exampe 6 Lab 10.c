#include<stdio.h>

void fun(int n)
{
	if(n<=0)
	return;
	else{
		 fun(n-1);
		printf("%d\n",n);
	}
}

int main(){
	fun(4);
}
//fun(0)=0
//fun(1)=1+0
//fun(2)=1+1
//fun(3)=1+2