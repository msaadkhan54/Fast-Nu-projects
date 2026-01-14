#include<stdio.h>
void even_odd(int x){
	if(x%2==0)
	printf("Even\n");
	else printf("Odd\n");
}

int sum(int *ptr){
	int sum=0;
	for(int i=0;i<5;i++)
    {
	    sum+=*(ptr +i);
	}
	even_odd(sum);
	return sum;
}


int main(){
	int arr[5]={1,2,3,4,5};
	int result=sum(arr);
	printf("The total sum is %d",result);
}
