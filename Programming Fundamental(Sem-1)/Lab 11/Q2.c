#include<stdio.h>
struct record{
	int id;
	char Name[50];
	float salary;
};
int main(){
	int i;
	float sum=0;
	FILE *ptr=fopen("SalRecord.dat","wb");
	if(ptr==NULL)
	{
		printf("Error:(");
		return 1;
	}
	struct record r1[4];
	for(i=0;i<4;i++)
	{
		printf("Enter name:");
		scanf("  %[^\n]s",r1[i].Name);
		
		printf("Enter id:");
		scanf("%d", &r1[i].id);
		
		printf("Enter Salary:");
		scanf("%f", &r1[i].salary);
	}
	fwrite(&r1,sizeof(struct record),4,ptr);
	fclose(ptr);
	ptr=fopen("SalRecord.dat","rb");
	if(ptr==NULL)
	{
		printf("Error:(");
		return 1;
	}
	struct record temp;
	while(fread(&temp,sizeof(struct record),1,ptr)){
		printf("Name: %s\tID: %d\tSalary: %.2f\n",temp.Name,temp.id,temp.salary);
		sum+=temp.salary;
	}
	printf("The total salary is : %.3f",sum);
	fclose(ptr);
}
