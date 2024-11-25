#include<stdio.h>
struct Employee{
	char name[50];
	int employeeId;
	float salary;
};

struct Department{
	char name[50];
	int employeeCount;
	struct Employee employee[100];
};
int main(){
	int i,j,k;
	struct Department d1[3];
    for(j=0;j<3;j++)
    {
	    printf("Enter the Department '%d' name:",j+1);
	    if(j>0)
	    getchar();
    	scanf("   %[^\n]s",d1[j].name);
    	printf("Enter the number of employees:");
    	scanf("%d", &d1[j].employeeCount);
    	float sum=0;
   		for(i=0;i<d1[j].employeeCount;i++)
	    {
		printf("EMPLOYEE %d \n",i+1);
		
		printf("Enter Name :");
		scanf("  %[^\n]s",d1[j].employee[i].name);
		
		printf("Enter id");
		scanf("%d",&d1[j].employee[i].employeeId);
		
		printf("Enter salary:");
		scanf("%f",&d1[j].employee[i].salary);
    	}
    	for(k=0;k<d1[j].employeeCount;k++)
    	{
    		sum+=d1[j].employee[k].salary;
    		
		}
		printf("The total salary of department '%s' is %.3f\n",d1[j].name,sum);
    }
}
