#include<stdio.h>
  int main()
{
	int age,tickets_quantity,cost,total_cost;
	int discounted_price;
	char seat_type;
	printf("Enter the Quantity of tickets.\n");
	scanf("%d", &tickets_quantity);
	printf("Enter age.\n");
	scanf("%d", &age);
	if(age>=16 && age<=64)
	    {
	    	printf("enter seat type.\n");
			scanf(" %c", &seat_type);	
		  if(seat_type=='r')
		  { printf(" the cost of ticket is 800.\n");		  
	        cost=800;}
	      else if(seat_type=='v'){
	        printf(" the cost of ticket is 1000.\n");		  
	        cost=1000;
		}
		  else if(seat_type=='p'){
		    printf(" the cost of ticket is 1500.\n");		  
	        cost=1500;
		}
	    }
	else if(age>=65)
	    {
	    	printf("enter seat type.\n");
	    	scanf(" %c", &seat_type);
		  if(seat_type=='r')
		  { printf(" the cost of ticket is 700.\n");		  
	       cost=700;}
	      else if(seat_type=='v')
	       { printf(" the cost of ticket is 900.\n");		  
	       cost=900;}
		  else if(seat_type=='p')
		   { printf(" the cost of ticket is 1300.\n");		  
	       cost=1300;}
	    }
	else{
		printf("invalid age.\n");
	}
	total_cost=cost*tickets_quantity;
	printf("the total cost is:%d.\n",total_cost);
	if(total_cost>3500)
	{ printf("the discount of 15per is applied on total cost.\n");
	  int discounted_price=total_cost*0.85;
	  printf("the after amount is:%d.\n",discounted_price);
	}
	else{
		printf("no discount");
	}    
	    
	    
}
