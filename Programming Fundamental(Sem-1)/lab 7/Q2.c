#include<stdio.h>
int main(){
	int num[]={1,2,3,4,5,6,7,8,9};
	for(int i=0;i<=9;i++){
		if(num[i]==4)
		printf("At index %d the value is %d",i,num[i]);
	}
}

