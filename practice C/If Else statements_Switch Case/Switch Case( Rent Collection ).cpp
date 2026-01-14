#include<stdio.h>
int main(){
	int num,rent,rent_0,rent_1,rent_2,rent_3,rent_4,rent_5,rent_6,com_rent0,com_rent1,com_rent2,com_rent3,com_rent4,com_rent5,com_rent6;
 printf("The details of rent collected from each floor and combine rent collected from 3 Buildings of each floor.\n");
 printf("Enter\n 0:for ground floor\n 1:for first floor\n 2:for second floor\n 3:for third floor\n 4:for fourth floor\n 5:for fifth floor\n 6:for sixth floor\n floor:");
 scanf("%d", &num);
 switch(num)
 {
 	case 0:
 		printf("The rent for GROUND FLOOR.\n");
 		rent_0=50000*8;
 		printf("The rent is %d",rent_0);
 		printf("The combine rent of each floor of the 3 buildings");
 		com_rent0=rent_0*3;
 		printf("\n %d",com_rent0);
 		break;
 	case 1:
	 	printf("The rent for FIRST FLOOR.\n");
	 	printf("The road facing has to pay 50000 extra.\n");
 		rent_1=35000*4+5000*2;
 		printf("The rent is %d",rent_1);
 		printf("The combine rent of each floor of the 3 buildings");
 	    com_rent1=rent_1*3;
 		printf("\n %d",com_rent1);
 		break;
 	case 2:
 		printf("The rent for SECOND FLOOR.\n");
	 	printf("The road facing has to pay 50000 extra.\n");
 		rent_2=30000*4+5000*2;
 		printf("The rent is %d",rent_2);
 		printf("The combine rent of each floor of the 3 buildings");
 	    com_rent2=rent_2*3;
 		printf("\n %d",com_rent2);
 		break;
 	case 3:
	 	printf("The rent for THIRD FLOOR.\n");
	 	printf("The road facing has to pay 50000 extra.\n");
 		rent_3=30000*4+5000*2;
 		printf("The rent is %d",rent_3);
 		printf("The combine rent of each floor of the 3 buildings");
 		com_rent3=rent_3*3;
 		printf("\n %d",com_rent3);	
 		break;
 	case 4:
 		printf("The rent for FOUR FLOOR.\n");
	 	printf("The road facing has to pay 50000 extra.\n");
 		rent_4=30000*4+5000*2;
 		printf("The rent is %d",rent_4);
 		printf("The combine rent of each floor of the 3 buildings");
 		com_rent4=rent_4*3;
 		printf("\n %d",com_rent4);	
 		break;
 	case 5:
	 	printf("The rent for FIVE FLOOR.\n");
	 	printf("The road facing has to pay 50000 extra.\n");
 		rent_5=30000*4+5000*2;
 		printf("The rent is %d",rent_5);
 		printf("The combine rent of each floor of the 3 buildings");
 		com_rent5=rent_5*3;
 		printf("\n %d",com_rent5);	
 		break;	
 	case 6:
	 	printf("The rent for SIX FLOOR.\n");
	 	printf("The road facing has to pay 50000 extra.\n");
 		rent_6=30000*4+5000*2;
 		printf("The rent is %d",rent_6);
 		printf("The combine rent of each floor of the 3 buildings");
 		com_rent6=rent_6*3;
 		printf("\n %d",com_rent6);	
 		break;
	default:
	printf("The floor entered is invalid\n");
 }  
    printf("THANK YOU");
    

}
