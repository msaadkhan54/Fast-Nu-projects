#include<stdio.h>

int fabonacci(int n){
	if(n==1 || n==2)
	return n-1;
	else{
		return fabonacci(n-1)+fabonacci(n-2);
	}
}

int main(){
	int n=5;
	for(int i=0;i<n;i++){
		printf("%d ",fabonacci(i+1));
	}
}