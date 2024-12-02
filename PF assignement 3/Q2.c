#include<stdio.h>
#include<string.h>
struct player{
	int ballScores[12];
	char playerName[50];
	int totalScore;
};

void playGame(struct player *ptr){
	int i,score;
	for(i=0;i<12;i++){
		printf("Score of ball %d\n",i+1);
		scanf("%d",&ptr->ballScores[i]);
		
		score=ptr->ballScores[i];
		int flag=validateScore(score);
		if(flag)
		{
			ptr->ballScores[i]=0;
		}
	}
}

int validateScore(int score){
	if(!(score>=0 &&score<=6))
	{
		return 1;
	}
	return 0;
}
void findWinner(struct player *ptr,struct player *itr){
	int sum1=0,sum2=0,i;
	for(i=0;i<12;i++)
	{
		sum1=sum1+(ptr->ballScores[i]);
		sum2=sum2+(itr->ballScores[i]);
	}
	ptr->totalScore=sum1;
	itr->totalScore=sum2;
	if(sum1>sum2)
	printf("The WINNER is 'player1'!\n\n");
	else printf("The WINNER is 'player2'!\n\n");
}

void displayMatchScore(struct player p1,struct player p2){
	printf("Name\t\tBALL SCORE\t\t\tTOTAL SCORE\n");
	printf("%s\t",p1.playerName);
	int i;
	for(i=0;i<12;i++)
	{
		printf("%d,",p1.ballScores[i]);
	}
	printf("\t%d\n",p1.totalScore);
	
	printf("%s\t",p2.playerName);
	for(i=0;i<12;i++)
	{
		printf("%d,",p2.ballScores[i]);
	}
	printf("\t%d\n",p2.totalScore);
}
int main(){
	struct player player1,player2,*ptr,*itr;
	
	printf("Enter Name for player 1:");
	getchar();
	fgets(player1.playerName,50,stdin);
	player1.playerName[strcspn(player1.playerName,"\n")]='\0';
	
	printf("Enter Name for player 2:");
	getchar();
	fgets(player2.playerName,50,stdin);
	player2.playerName[strcspn(player2.playerName,"\n")]='\0';
	
	
	ptr=&player1;
	itr=&player2;
	printf("PLAYER '1'\n\n");
	playGame(ptr);
	
	printf("PLAYER '2'\n\n");
	playGame(itr);
	
	findWinner(ptr,itr);
	
	displayMatchScore(player1,player2);
}
