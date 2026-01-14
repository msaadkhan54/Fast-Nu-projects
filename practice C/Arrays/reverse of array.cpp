#include<stdio.h>
int main(){
	int i,num,arr[5]={1,2,3,4,5},rev_num[5];
    for(i=0;i<5;i++){
    	rev_num[4-i]=arr[i];
	}
	for(i=0;i<5;i++){
		printf("%d,",rev_num[i]);
	}
}
