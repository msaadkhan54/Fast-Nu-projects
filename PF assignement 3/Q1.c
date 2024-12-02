#include<stdio.h>
#include<string.h>
struct joining{
	int date;
	int month;
	int year;
};

typedef struct employees{
  int employeeCode;
  char employeeName[50];
  struct joining join;
}employees;

void initialize(employees *ptr){
	int i;
	for(i=0;i<4;i++)
	{
		printf("EMPLOYEE '%d'\n",i+1);
		
		printf("Enter Code:");
		scanf("%d",&ptr[i].employeeCode);
		
		printf("Enter Name:");
		getchar();
		fgets(ptr[i].employeeName,50,stdin);
		ptr[i].employeeName[strcspn(ptr[i].employeeName,"\n")]='\0';
		
		printf("Enter Date:");
		scanf("%d",&ptr[i].join.date);
		
		printf("Enter Month:");
		scanf("%d",&ptr[i].join.month);
		
		printf("Enter Year:");
		scanf("%d",&ptr[i].join.year);
	}
}

void tenure(employees *ptr,int day,int month,int year){
	int i=0;
	int j=0;
	int t_year;
	for(i=0;i<4;i++){
	t_year=year-ptr[i].join.year;
	if(month<ptr[i].join.month)
	t_year--;
	if(month==ptr[i].join.month && day<ptr[i].join.date)
	t_year--;
	if(t_year>=3)
	{
		printf("Code\tName\tJoining Date\n");
		printf("%d\t%s\t%d-%d-%d\n\n",ptr[i].employeeCode,ptr[i].employeeName,ptr[i].join.date,ptr[i].join.month,ptr[i].join.year);
		j++;
	}}
	printf("Count:%d\n\n",j);
}

int main(){
	employees arr[4];
	initialize(arr);
	int day,month,year;
	printf("Enter current date 'eg:DD MM YYYY' \n");
	scanf("%d %d %d",&day,&month,&year);
	tenure(arr,day,month,year);
}
