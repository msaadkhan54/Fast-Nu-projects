#include<stdio.h>
int main(){
	char slogans[3][20];
	int i,j;
	for(int i=0;i<3;i++)
	{
		printf("enter %d slogan\n",i+1);
		fgets(slogans[i], 20, stdin);
	}
	for(int i=0;i<3;i++)
	{   
	    int freq[123]={0};
		for(int j=0;slogans[i][j]!='\0';j++)
		{
			if(slogans[i][j]==32 || slogans[i][j]>=97 && slogans[i][j]<=122)
			{
			    freq[slogans[i][j]]++;
		    }
		}
		printf("For slogan %d\n",i+1);
	    for(int k=0;k<123;k++)
	    {
	        if(freq[k]>0)
	        printf("'%c': '%d'\n", k,freq[k]);
	    }
	}
}

