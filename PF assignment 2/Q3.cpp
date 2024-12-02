#include<stdio.h>
#include<string.h>
char *min(char *word)
{
	static char arr[100];
	int n= strlen(word);
	int j=0;
	for(int i=0;i<n;i++)
	{
		if(word[i] == word[i-1])
		continue;
		else
		{
			arr[j]=word[i];
			j++;
		}
	}
	arr[j]='\0';
	return arr;
}


int main(){
	char word[3][20];
	int i,j,k;
	for(int i=0;i<3;i++)
	{
		printf("enter input %d \n",i+1);
		scanf("%s", &word[i]);
	}
	for(i=0;i<3;i++)
	{
		int freq[123]={0};
		
		for(j=0;word[i][j]!='\0';j++)
		{
			if(word[i][j]>=97 && word[i][j]<=122)
			freq[word[i][j]]++;  
		}
		
		
		printf("for input %d\n",i+1);
		int total_removed=0;
		
		
		for(k = 97; k <= 122; k++)
	    {
            if(freq[k] > 1) {
            total_removed += (freq[k] - 1);  
			printf("The characters '%c' removed are %d\n",k,total_removed);}
		}
		
		
	char *processed_word = min(word[i]);
	printf("The processed word is %s\n",processed_word);
	}
}
