#include<stdio.h>
typedef struct detail{
	char make[20];
	int model;
	float price;
	float mileage;
}detail;

void display(detail arr[],int size){
	int i;
	for(i=0;i<size;i++){
		if(arr[i].model==0){
			continue;
		}
		printf("MAKE='%s' , MODEL='%d' , PRICE='%.2f' , MILEAGE='%.1f'\n",arr[i].make,arr[i].model,arr[i].price,arr[i].mileage);
	}
}

void add(detail arr[],int size){
	int i=0;
	for(i=0;i<size;i++){
		if(arr[i].model==0){
			
			printf("Enter Make of the car\n");
			scanf(" %[^\n]s", arr[i].make );
			
			printf("Enter Model of the car.\n");
			scanf("%d", &arr[i].model);
			
			printf("Enter Price of the car.\n");
			scanf("%f", &arr[i].price);
			
			printf("Enter Mileage of the car.\n");
			scanf("%f", &arr[i].mileage);
			
			printf("Entry is successful :)\n");
			break;
		}
	}
}	

void search(detail arr[],int size){
	char input[20];
	int i;
	
	printf("Enter MAKE of the car :");
	scanf("%s",input);
	
	for(i=0;i<size;i++){
		if(strcmp(arr[i].make,input)==0){
			printf("MAKE='%s' , MODEL='%d' , PRICE='%.2f' , MILEAGE='%.1f'\n",arr[i].make,arr[i].model,arr[i].price,arr[i].mileage);}	
	}
}

int main(){
	int ch;
	detail car[6]={{"Toyota",2012,200000.32,12.1},
	               {"Honda",2002,403200.65,11.0},
	               {"Sizuki",2016,6500400.43,15.6},
	               {"KIA",2014,7600300.71,10.3},
	               {"Lexus",2010,3409876.00,8.3},
	               {"",0,0.0,0}
	};
	
	int size=sizeof(car)/sizeof(car[0]);
	printf("1:Display Available car\n2:Search Car\n3:Add Car\n4:Exit!\n");
	
	printf("Enter number 1-4 :");
	scanf("%d",&ch);
	
	switch(ch){
		case 1:
			display(car,size);
			break;
		case 2:
			search(car,size);
			break;
		case 3:
			add(car,size);
			break;
		case 4:
		    printf("Program has ended\n");			
		default :
		    printf("Invalid input :(");    
	}
}
