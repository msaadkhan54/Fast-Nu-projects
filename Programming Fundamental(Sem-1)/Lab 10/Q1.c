#include<stdio.h>

int add(int n){
       int temp=n;
       if(temp==0)
       return;
	   else{
	   	return n%10 + add(n/10);
	   }
	    
	
}


int main(){
	int n;
    scanf("%d", &n);
    
	printf("The sum is %d", add(n));   
}