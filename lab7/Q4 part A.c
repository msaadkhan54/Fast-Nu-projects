#include<stdio.h>
int main(){
	char name[20];
	char phone[20];
	char email[20];
	int a=0,b=0,c=1;
	 
	printf("Enter name:");
	scanf("%s",name);
	
	printf("\nEnter email:");
	scanf(" %s  ",email);
	
	printf("\nEnter Phone number:");
	scanf("  %19s  ",phone);
	
	
	for(int i=0;i<20;i++){
		if((name[i]>='a' && name[i]<='z') ||  (name[i]>='A' && name[i]<='Z') || (name[i]=' ')){
		a=1;
		}
		else{
			a=0;
			break;} 
		}
		 if(a==1)
     printf("Input is valid name\n");
     if(a==0)
     printf("Input is invalid name\n");
     
     
     for(int i=0;i<20 && email[i]!='\0';i++){
     	if((email[i]>='a' && email[i]<='z') || (email[i]>='0' && email[i]<='9' ) ||
		  (email[i]=='.') ||
		  (email[i]=='_') ||
		  (email[i]=='-') ||
		  (email[i]=='@') )
			 {
     		b=1;
    }
        else{
	    b=0;
	    break;}
        
	 }
	 if(b==1){
	 	printf("Valid input of eamil\n");
	 }
	 else if(b==0) printf("Invalid input of email\n");
	 
	 for(int i=0;i<20 && phone[i]!='\0';i++){
	 	if(!((phone[i]>='0' && phone[i]<='9') || (phone[i]=='-') || (phone[i]=='+'))){
	 	c=0;
	 	break;}
	 	 
	 }
	 if(c==1)
		printf("Input of phone is valid");
		else printf("Input is invalid of phone");  
     
	return 0;
	
	}

