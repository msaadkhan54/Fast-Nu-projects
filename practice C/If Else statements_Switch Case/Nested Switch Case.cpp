#include<stdio.h>
 int main()
 {
 	int id,pass;
 	printf("Enter id.\n");
 	scanf("%d", &id);
 	printf("enter password,\n");
 	scanf("%d", &pass);
 	switch(id)
    {   case 101:
 			switch(pass)
 			{ 	case 001:
 				printf("your password is correct.\n");
 				break;
		    	 default:	
 				printf("your password is incorrect.\n");
 				break;	}
 		break;		
		case 102:
			switch(pass)
			{   case 002:
				printf("your password is correct.\n");
				break;
				default:
				printf("your password is incorrect.\n");
				break;	}
		break;
		default:
		printf("id is incorrect");		
		
			}
	return 0;		
 }
