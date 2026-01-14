#include<stdio.h>
int main()
{
    int a,WS;
	int F,B,E,H;
	double t_week_expense=F+B+H+E;
	double monthly_inc;
	double month_expense=t_week_expense*4;
	double yearly_expense=month_expense*12;  
	printf("select\n1:Calculate Yearly Salary and Assign a salary class\n2:Calculate Monthly Expenses and assign a household class\n3:Calculate Monthly Deficit or Surplus\n4:Exit\n");
	scanf("%d", &a);
	switch(a)
	{ case 1:
		int yearly_sal;
		printf("Enter WEEKLY SALARY.\n");
		scanf("%d", &WS);
		yearly_sal=WS*4*12;
		printf("the YEARLY SALARY is:%d\n",yearly_sal);
		if(yearly_sal>900000)
		  printf("High Income\n");
		else if(yearly_sal>600000)
		  printf("Middle Income\n");
		else if(yearly_sal<300000)
		  printf("Low Income\n");
		 else
		 printf("none"); 
	  break;
	  case 2:
	    printf("Enter WEEKLY EXPENSE\n");
	    printf("food items\n");
	    scanf("%d", &F);
	    printf("bill");
	    scanf("%d", &B);
	    printf("education");
	    scanf("%d", &E);
	    printf("health");
	    scanf("%d", &H);
	    printf(" TOtal weekly expense is:%.2lf",t_week_expense);
	    printf("Total monthly expense is:%.2lf",month_expense);
	    printf("Total yearly expense is:%.2f",yearly_expense);
	    if(yearly_expense>1000000.0)
	    printf("ELITE CLASS\n");
	    else if(yearly_expense>600000.0)
	    printf("HIGH CLASS");
	    else if(yearly_expense>300000.0)
	    printf("MEDIUM CLASS");
	    else
	    printf("LOW CLASS");
	    break;
	   case 3:
	   	double remaining_amount;
	   	double WI,ME;
	    printf("Enter weekly income.\n");
		scanf("%lf", &WI);
		printf("Enter TOTAL montlhy expense./n"); 
		scanf("%lf", &ME);
	    monthly_inc=WI*4;
		printf("The monthly income is:%.2lf",monthly_inc);
	    remaining_amount=monthly_inc-ME;
		printf("The montlhy expense is:%.2lf",ME);
		printf("The remaining amount is:%.2lf",remaining_amount);
		if(ME>monthly_inc)
		printf("deficit");
		else
		printf("surplus");
		break;
	  case 4:
	    printf("ALLAH HAFIZ");
		break;
	default:
	    printf("invalid choice");		
			      
	}
}
