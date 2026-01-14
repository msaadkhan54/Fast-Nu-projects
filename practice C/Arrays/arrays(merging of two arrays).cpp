#include<stdio.h>
int main(){
	int arr1[3],arr2[3],i;
	printf("Enter  3 numbers in ascending order.\n");
	for(i=0;i<3;i++){
		scanf("%d",&arr1[i]);
		printf("\n");
	}
	printf("Enter 3 more numbers in ascending order.\n");
	for(i=0;i<3;i++){
		scanf("%d",&arr2[i]);
		printf("\n");
	}
	for(i=2;i>=0;i--){
		printf("%d%d ",arr1[i],arr2[i]);
	}
}
