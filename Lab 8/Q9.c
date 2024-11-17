#include<stdio.h>
int main(){
	int range;
	printf("Enter range:");
	scanf("%d", &range);
	if(range%2!=0){
		
		for(int i=range;i>=1;i-=2)
		{
			printf("%d",i);
			printf("\n");
		}
	}
}

