#include<stdio.h>
int main(){
	int N;
	printf("Enter the number of elements you want:");
	scanf("%d", &N);
	int num[N],i;
	int count[N];
	for(int i=0;i<N;i++){
		scanf("%d",&num[i]);
		printf("\n");
	}
	for(int i=0;i<N;i++){
		count[i]=0;
	}
	for(int i=0;i<N;i++){
		count[num[i]]++;
	}
	for (int i = 0; i < N; i++) {
        if (count[i] > 1) {
            printf("the number %d occurs more than once\n",num[i]);}
	}}

