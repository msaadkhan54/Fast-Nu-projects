#include<stdio.h>

void printHello(int n){
	if(n==0)
	return;
	printf("Hello\t");
	printWorld(n-1);
}

void printWorld(int n){
	if(n==0)
	return;
	printf("World\n");
	printHello(n-1);
}
int main(){
	printHello(5);
}