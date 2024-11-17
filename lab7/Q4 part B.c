#include<stdio.h>
int main(){
   int num[]={4,1,6,8,10,21,8,9,2,6};
   int low=num[0],high=0;
   for(int i=0;i<10;i++){
   	if(num[i]<low)
   	low=num[i];
   	if(num[i]>high)
   	high=num[i];
   }
   printf("The low number is %d\n",low);
   printf("The high number is %d",high);
}

