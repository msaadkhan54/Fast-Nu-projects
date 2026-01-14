#include<stdio.h>
void modify(int *m, int n);
int main(){
	int arr[10]={1,2,3,4,5,6,7,8,9,10};
	modify(arr,10);
}
void modify(int *m,int n){
	for(int i=0;i<n;i++){
	   int	a=*m*3;
		m++;
		printf("at address %d the value is %d\n",i,a);
	}
} 
