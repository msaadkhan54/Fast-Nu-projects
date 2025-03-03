#include<stdio.h>
#define MAX_temp 55.0

void compare(int input){
	static int count=0;
	if(input>MAX_temp)
	count++;
	printf(" %d times the temprature exceeded\n",count);
}

int main(){
	float input,input1,input4,input2,input3;
	scanf("%f", &input);
	compare(input);
	
	scanf("%f", &input1);
	compare(input1);
	
	scanf("%f", &input2);
	compare(input2);
	
	scanf("%f", &input3);
	compare(input3);
	
	scanf("%f", &input4);
	compare(input4);
}
