#include<stdio.h>
#include<stdlib.h>
struct employee{
	int ratings[20][4];
	int totalScore;
};

void inputEmployees(int **rating,int numEmployees,int periods){
	int i,j,rate;
	for(i=0;i<numEmployees;i++)
	{
		printf("For EMPLOYEE %d:\n",i+1);
		for(j=0;j<periods;j++)
		{
			do{
			scanf("%d",&rate);
			*(rating +(i*periods)+j)=rate;
			if(rate<1 || rate>10)
			printf("Invalid! Enter again :(\n");
			}
			while(rate<1 || rate>10);
		}
	}
}

void displayPerformance(int **rating,int numEmployees,int numPeriods){
	int i,j;
	for(i=0;i<numEmployees;i++)
	{
		printf("FOR EMPLOYEE '%d':\n",i+1);
		for(j=0;j<numPeriods;j++)
		{
			if(numPeriods==1)
			{
				printf("Period 1: %d",*(rating +(i*numPeriods)+j));
			}
			else if(numPeriods==2 || numPeriods==4)
			{
				printf("Period %d: %d\t",j+1,*(rating +(i*numPeriods)+j));
			}
		}
		printf("\n\n");
	}
}

int findEmployeeOfTheYear(int** ratings, int numEmployees, int numPeriods){
	int i,j,sum=0;
	int index=0;
	float avg[numEmployees];
	for(i=0;i<numEmployees;i++)
	{
		sum=0;
		for(j=0;j<numPeriods;j++)
		{
			sum+=*(ratings +(i*numPeriods)+j);
		}
		avg[i]=(sum+0.0)/(numPeriods+0.0);
	}
	for(i=0;i<numEmployees-1;i++)
	{
		if(avg[i]<avg[i+1])
		{
			index=i+1;
		}
	}
	return index+1;
} 

int findHighestRatedPeriod(int** ratings, int numEmployees, int numPeriods) {
    int i, j;
    int sum, maxSum = -1;
    int highestPeriod = 0;

    
    for (j = 0; j < numPeriods; j++) {
        sum = 0;
        for (i = 0; i < numEmployees; i++) {
            sum += *(ratings + (i * numPeriods) + j); 
        }
       
        if (sum > maxSum) {
            maxSum = sum;
            highestPeriod = j + 1; 
        }
    }
    
    return highestPeriod;
}

int findWorstPerformingEmployee(int** ratings, int numEmployees, int numPeriods) {
    int i, j, sum, lowSum = 1000; 
    int worstEmployee = 0;

    for (i = 0; i < numEmployees; i++) {
        sum = 0;
        for (j = 0; j < numPeriods; j++) {
            sum += *(ratings + (i * numPeriods) + j);
        }
        if (sum < lowSum) {
            lowSum = sum; 
            worstEmployee = i; 
        }
    }
    return worstEmployee + 1; 
}


int main(){
    int numEmployees,period,high;
	printf("Enter the total number of employees: ");
	scanf("%d",&numEmployees);
	
	printf("Enter the evaluation period once for all of the employees: ");
	scanf("%d",&period);

   	int *ptr;
	ptr=(int*) malloc(numEmployees*period*sizeof(int));
	int *str;
	str=ptr;	
	inputEmployees(str,numEmployees,period);
	displayPerformance(str,numEmployees,period);
	printf("The Employee with Highest Average Rating is Employee '%d'\n\n",findEmployeeOfTheYear(str,numEmployees,period));
	high=findHighestRatedPeriod(str,numEmployees, period);
	printf("The Highest Period of Employees is '%d'\n\n",high);
	printf("The worst performing employee is '%d'",findWorstPerformingEmployee(str, numEmployees, period));
	free(ptr);
}
