#include<stdio.h>
	struct manage{
		int number;
		char *dep_city;
		char *des_city;
		char *date;
		int avail_seats;
	};
	
void display(struct manage a[]){
	int i;
	for(i=0;i<3;i++){
		printf("number=%d, Departure=%s, Destiny=%s, Date=%s, Available Seats=%d\n",a[i].number,a[i].dep_city,a[i].des_city,a[i].date,a[i].avail_seats);
	}
}

void book(){
	int number,seats;
	char des_city[20],dep_city[20],date[10];
	printf("\n\n\t\t\t\tBOOKING:\n");
		printf("Enter Flight number\n");
		scanf("%d", &number);
		
		printf("Enter the Departure City\n");
		scanf("%s",dep_city);
		
		printf("Enter the Destination city\n");
		scanf("%s",des_city);
		
		printf("Enter the date of departure\n");
		scanf("%s",date);
		
		printf("Enter Required Seats\n");
		scanf("%d",seats);
}	

int main(){
    struct manage open[3]={{1,"Karachi","Lahore","12-3-24",43},
                   {2,"Karachi","Quetta","3-6-24",57},
				   {3,"Islammabad","Swat","23-5-24",12}    
	};
	display(open);
	book();	
}
