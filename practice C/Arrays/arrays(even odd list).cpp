#include<stdio.h>
int main(){
	int num[5],i,remainder,even[5],odd[5],j=0,k=0,count1=0,count2=0;
	for(i=0;i<5;i++){
		printf("Enter number for index %d\n",i);
		scanf("%d",&num[i]);
	}
	for(i=0;i<5;i++){
		remainder=num[i]%2;
		if(remainder==0){
		while(remainder==0){
		even[j]=num[i];
		j++;
		count1++;
		break;}}
		else {
		while(remainder!=0){
		odd[k]=num[i];
		k++;
		count2++;
		break;}}}
	printf("The even numbers are\n"); 
	for(j=0;j<count1;j++){
		printf("%d,",even[j]);
	}	
	printf("\nThe odd numbers are\n");
	for(k=0;k<count2;k++){
		printf("%d,",odd[k]);
	}	
	}

