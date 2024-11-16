#include<stdio.h>
#define constant 1/1000

void fun(int meter){
	static int i=1;
	float Km;
	Km=meter*constant;
	printf("The distance in kilometer is %.1fkm\n",Km);
	printf("The function is called %d\n",i);
	i++;
}

int main(){
	float meters;
	printf("Enter in meters the distance covered\n");
	scanf("%f", &meters);
	fun(meters);
	printf("Enter in meters the distance covered\n");
	scanf("%f", &meters);
	fun(meters);
	
}
