#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int initialize(char ****s)
{
	int n;
	printf("Enter the number of PETS you want to add: ");
	scanf("%d",&n);
	
	*s=(char***) malloc(n*sizeof(char**));
	if(*s==NULL){
		printf("Memory Allocation failed\n");
	return 1;
    }
	return n;
}

int addSupplies(char ****s,int n){
	char buffer[50];
	int i,j,supplies;

	for(i=0;i<n;i++)
	{
		printf("Enter the number of supplies for index %d: ",i);
		scanf("%d", &supplies);
		
		(*s)[i]=(char**) malloc(supplies*sizeof(char*));
		
		for(j=0;j<supplies;j++)
		{
			printf("Enter the supply '%d': ",j+1);
			scanf("%s",buffer);
			
			int l=strlen(buffer);
	    	l=l+1;
	    	(*s)[i][j]=(char*)malloc(l*sizeof(char));
	    	strcpy((*s)[i][j],buffer);
		}
	}
	return supplies;
}

void updateSupplies(char ****s){
	int index,supplies,i,j;
	char buffer[50];
	
	printf("Enter index at which you want to do update: ");
	scanf("%d",&index);
	
	printf("Enter the number of supplies for index %d: ",index);
	scanf("%d", &supplies);
	
	for(i=0;i<supplies;i++)
	{
		printf("Enter the supply '%d'",i+1);
		scanf("%s",buffer);
		int l=strlen(buffer);
    	l=l+1;
    	(*s)[index][i]=(char*)malloc(l*sizeof(char));
    	strcpy((*s)[index][i],buffer);
	}
		printf("The index is successfully updated :) \n");
}

void removeSupplies(char ****s,int *n){
	int index,i;
	
	printf("Enter index which you want to delete: ");
	scanf("%d",&index);
	
	free((*s)[index]);
	for(i=index;i<*n-1;i++)
	{
		(*s)[i]=(*s)[i+1];
	}
	*s = (char***)realloc(*s, sizeof(char**) * ((*n)-1));
	 if (*s == NULL && (*n - 1) > 0) {
        printf("Memory reallocation failed. Exiting...\n");
        exit(1);
    }
	*n=*n-1;
	printf("The index is successfully deleted :) \n");
}

void display(char ***s, int n,int supplies){
	int i,j;
	 printf("\nInventory:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<supplies;j++)
		{
			printf("Species %d: %s\n", i + 1,(*s)[i][j]);
		}
	}
		
		
	
}

int main(){
	int n,i;
	char ch;
	char ***speciesSupplies;
	n=initialize(&speciesSupplies);
	int supplies=addSupplies(&speciesSupplies,n);
	do{
	printf("\n\nEnter:\n");
	printf("1:Update Supplies\n");
	printf("2:Remove Supplies\n");
	printf("3:Display\n");
	printf("4:Exit\n");
	scanf("%d",&ch);
	
		if(ch == 1){
    		updateSupplies(&speciesSupplies);
		}
		else if(ch == 2){
			removeSupplies(&speciesSupplies, &n);
		}
		else if(ch == 3){
			display(speciesSupplies, n,supplies);
		}
		
    	
	}while(ch!=4);
	for( i=0;i<n;i++)
	{
		free(speciesSupplies[i]);
	}
	free(speciesSupplies);
}
