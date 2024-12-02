#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct {
    char title[100];      
    float rating;          
    int runtime;                 
} ContentMetadata;

int initializeEngagement(int ****engagementMatrix,int n)
{
    int categories,i,j;
	printf("Enter the number of categories from (1-3): ");
	scanf("%d",&categories);
	
	printf("\n\t1:Action    2:Drama    3:Comedy\n\n");
	
	(*engagementMatrix)=(int***)malloc(n*sizeof(int**));
	
	for(i=0;i<n;i++)
	{
		(*engagementMatrix)[i]=(int**)malloc(categories*sizeof(int**));
		
		for(j=0;j<categories;j++)
		{
			(*engagementMatrix)[i][j]=(int*)malloc(1*sizeof(int));
		}
	}
	return categories;
}

void addData(int ****engagementMatrix,int n,int categories){
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<categories;j++)
		{
			printf("Enter '1' for Like and '0' for Dislike for USER '%d' and COLUMN '%d': ",i+1,j+1);
			scanf("%d", &(*engagementMatrix)[i][j]);
		}
		printf("\n\n");
	}
}

void updateEngage(int ****engagementMatrix,int n,int categories){
	int index,i;
	
	printf("Enter User number you want to update: ");
	scanf("%d", &index);
	
	for(i=0;i<categories;i++)
	{
		printf("Enter column '%d': ",i+1);
		scanf("%d", &(*engagementMatrix)[index-1][i]);
	}
	printf("Successfully Updated :)\n\n");
}

int initializeDevice(int ****deviceMatrix,int n){
	int numDevices,i,j;
	(*deviceMatrix)=(int***)malloc(n*sizeof(int**));
	
	printf("Number of devices(1-3): ");
	scanf("%d",&numDevices);
	printf("\n1:Smart Tv's\t2:Laptops\t3:SmartPhones\n\n");
	
	for(i=0;i<n;i++)
	{
		(*deviceMatrix)[i]=(int**)malloc(numDevices*sizeof(int**));
		for(j=0;j<numDevices;j++)
		{
			(*deviceMatrix)[i][j]=(int*)malloc(3*sizeof(int));
		}
	}
	return numDevices;
}

void addDevice(int ****deviceMatrix,int n,int numDevices){
	int i,j;
	 for ( i = 0; i < n; i++) {
        for (j = 0; j < numDevices; j++) {
            printf("\nEnter data for User %d, Device %d:\n", i + 1, j + 1);
            
            printf("Enter resolution preference (e.g., 720, 1080, 2160): ");
            scanf("%d", &(*deviceMatrix)[i][j][0]);

            printf("Enter playback history (last position in seconds): ");
            scanf("%d", &(*deviceMatrix)[i][j][1]);

            printf("Enter bandwidth usage (in Mbps): ");
            scanf("%d", &(*deviceMatrix)[i][j][2]);
        }
    }
}


int main(){
	int n,i,j,categories,numCategory,contents,devices;
	int ***engagementMatrix;
	int ***deviceMatrix;
	ContentMetadata ***contentMatrix;
	printf("Enter the number of users there are: ");
	scanf("%d", &n);
	
	categories=initializeEngagement(&engagementMatrix,n);
	
    addData(&engagementMatrix,n,categories);
    
    updateEngage(&engagementMatrix,n,categories);
    
    devices=initializeDevice(&deviceMatrix,n);
    
    addDevice(&deviceMatrix,n,devices);
    printf("Category: ");
    printf("\n1:Action\t2:Drama\t3:Comedy\n\n");
    
    printf("Enter number of contents(1-3): ");
    scanf("%d", &numCategory);
    
    contentMatrix = (ContentMetadata***)malloc(numCategory * sizeof(ContentMetadata**));
    for (i = 0; i < numCategory; i++) {
        contentMatrix[i] = (ContentMetadata**)malloc(3 * sizeof(ContentMetadata*));
    for (j = 0; j < 3; j++) {
           contentMatrix[i][j] = (ContentMetadata*)malloc(sizeof(ContentMetadata));
        }
    }
    //adding content
   for (i = 0; i < numCategory; i++) {
        if(i==0)printf("For Movie:\n");
    	else if(i==1)printf("For Series:\n");
    	else printf("For Show:\n");

        for ( j = 0; j < 3; j++) {
            printf("\nContent #%d:\n", j + 1);

            printf("Enter Title: ");
            scanf(" %[^\n]s", contentMatrix[i][j]->title);

            printf("Enter Runtime (in minutes): ");
            scanf("%d", &contentMatrix[i][j]->runtime);

            printf("Enter Rating (0.0 to 10.0): ");
            scanf("%f", &contentMatrix[i][j]->rating);
        }
    }

    
    for(i=0;i<n;i++)
    {
    	free(engagementMatrix[i]);
    	free(deviceMatrix[i]);
	}
	for (i = 0; i < numCategory; i++) {
        for (j = 0; j < 3; j++) {
            free(contentMatrix[i][j]);
        }
        free(contentMatrix[i]);
    }
    free(contentMatrix);
}
