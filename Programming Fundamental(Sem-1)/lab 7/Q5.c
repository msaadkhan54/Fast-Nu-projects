#include<stdio.h>
int main(){
	int weather[7],sum=0;
	printf("Enter weather:\n");
	for(int i=0;i<7;i++){
		scanf("%d",&weather[i]);
		printf("\n");
	}
	for(int i=0;i<7;i++){
		sum=sum+weather[i];
	}
	int average=sum/7;
	printf("The average weather of 7 days is %d\n",average);
	for(int i=0;i<7;i++){
		if(weather[i]>40 || weather[i]<0){
			printf("The Weather is extreme at %d\n",weather[i]);
		}
	}
}

