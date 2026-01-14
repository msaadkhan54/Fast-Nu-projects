#include<stdio.h>
int main(){
	char name[]="Fast Nuces !(1234)",count=0,count2=0,count3=0,count4=0,count5=0;
	for(int i=0;i<10;i++){
	    if(name[i]=='s'){
	    	count++;} 	 
	    }
	printf("The Number of 's' is %d\n",count);
	for(int i=0;i<10;i++){
		if(name[i]>='a' && name[i]<='z'){
			count2++;
		}
	} 
	printf("The small letters are %d\n",count2);
	for(int i=0;i<10;i++){
		if(name[i]>='A' && name[i]<='Z'){
			count3++;
		}
	}
  printf("The capital letters are %d\n",count3);
   for(int i=0;i<18;i++){
   	if(name[i]>=33 && name[i]<=47)
   	count4++;
   } 
   printf("The special character are %d\n",count4);
   for(int i=0;i<18;i++){
   	if(name[i]>=48 && name[i]<=57)
   	count5++;
   }
   printf("The number of digits are %d",count5);
  }
