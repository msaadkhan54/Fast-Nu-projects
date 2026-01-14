#include<stdio.h>
int main(){
	int i=1,j,spaces;
	while(i<=5)
	{
        spaces = 5 - i;
        while (spaces > 0) {
            printf(" ");
            spaces--;
        }
		j=1;
		while(j<=i)
		{
			
			printf("%d",j);
			printf(" ");
			j++;
		}
		printf("\n");
		i++;
	}
}
