#include<stdio.h>
typedef struct travel{
	char name[20];
	char destination[25];
	char duration[10];
	float cost;
	int seats;
}travel;

void display(travel arr[],int size){
	int i;
	for(i=0;i<size;i++)
	{
		printf("Package= %s,Destination= %s,Duration= %s, Cost=%.1f, Seats=%d\n\n",arr[i].name,arr[i].destination,arr[i].duration,arr[i].cost,arr[i].seats);
	}
}

void book(){
	char booking[20];
	printf("Enter Package name which you want to book:");
	scanf("%s",booking);
}

int main(){
	travel pak[5]={{"Tropical bliss","Maldives","2 hour",23000.4,34},
	                {"Mountain Explorer","Swat","3 hour",54000.0,21},
	                {"Cultural","Japan","2 hour",45000,56},
	                {"Desert","Dubai","1 hour",21000,67},
	                {"Wildlife","Africa","4 hour",432100.4,46}
	};
	int size=sizeof(pak)/sizeof(pak[0]);
	display(pak,size);
	book();
}
