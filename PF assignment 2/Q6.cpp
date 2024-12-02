#include<stdio.h>
int main()
{
	int n,rem;
	printf("Enter the number of Matchstick that are placed on the table.\n");
	scanf("%d", &n);
	rem=n%5;
	if(rem==0){
		printf("Whatever number of sticks he pick\n  Player A will lose the game.\n ");
	}
	else{
		if(rem>0 && rem<5)
		printf("The player A has to pick %d Match Stick in first attempt\n in order to win the game.",rem);
	}
}
