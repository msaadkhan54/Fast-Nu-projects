#include<stdio.h>
int main(){
	int n,i,new_value,pos;
	printf("Enter the size of an array.\n");
	scanf("%d",&n);
	int arr[n+1];
	for(i=0;i<n;i++){
		printf("Enter number for index %d the values entered must be in ascending order\n",i);
		scanf("%d",&arr[i]);
	}
		for(i=0;i<n;i++){
			printf("The element-%d:%d\n",i,arr[i]);
		}
	printf("Enter the value to be inserted.\n");
	scanf("%d",&new_value);
	for(i=0;i<n;i++){
		if(arr[i]>new_value)
		   pos = i;
		   break;
		}
	for(i=n;i>pos;i--)
	    arr[i]=arr[i-1];
	arr[pos]=new_value;
	    n++;
    // Display the updated array
    printf("After insertion, the array elements are:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}		


