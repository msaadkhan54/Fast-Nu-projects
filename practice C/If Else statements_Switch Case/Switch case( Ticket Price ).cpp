#include<stdio.h>
int main(){
	int roll_number,price,tickets,discount=0;
	printf("Enter 6 digit roll no in format of XXYYYY where'XX' is batch number and 'YYYY' is a roll number");
	scanf("%d",&roll_number);
	if(roll_number>=210000 && roll_number<=249999)
	printf("The roll number enterd is VALID\n");
	else printf("The roll number enterd is INVALID\n");
	int batch=roll_number/10000;
	switch(batch){
		case 21:
			price=1800;
			break;
		case 22:
		    price=1700;
		    break;
		case 23:
		    price=1600;
			break;
		case 24:
		    price=1500;
			break;
		default:
		    printf("Batch number entered is not valid.\n");				
	}
	printf("The number of tickets you have purchased\n");
	scanf("%d",&tickets);
	
	
	int total_price=tickets*price;
	printf("The total price is %d\n",total_price);
	
	
	int number=roll_number/100;
	if(number==10)
	discount=(total_price*0.1);	
	else if(number==20)
	discount=(total_price*0.2);
	else if(tickets>10)
	 discount=price;
	 printf("discount %d",discount);
	 
	int total_price_disc=total_price-discount;
	printf("The discounted price is %d",total_price_disc);
	
}
