#include<stdio.h>
int main(){
	int num[9];
	for(int i=0;i<9;i++){
		printf("Enter number");
		scanf("%d",&num[i]);
	}
	
	for(int i=8;i>=0;i--){
		printf("%d\n",num[i]);
	}
}

