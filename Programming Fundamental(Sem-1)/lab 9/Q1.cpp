#include<stdio.h>
int calculatefine(int d,int m,int y){
	int rd,rm,ry,totalDays=0,year=0,month=0,day=0;
	int fine=2,totalfine=0;
	printf("Enter the day,month and year on which you returned\n");
	scanf("%d %d %d", &rd, &rm, &ry);
	if(ry>=y){
	   year=ry-y;
	   if(rm>=m){
	        month=rm-m;
        	if(rd<d){
        	month-=1;
        	day=rd;}
			else
			day=rd-d;}
	   else{
        	month=(12-m)+rm;
        	year-=1;}
}
    totalDays=year*365 + month*30 + day;
    totalfine=fine*totalDays;
    return totalfine;
    
}
int main(){
	int day,month, year;
	printf("Enter the day,month and year on which user borrows a book.\n");
	scanf("%d %d %d", &day , &month, &year);
	int fine=calculatefine(day,month,year);
	printf("The total fine is $%d",fine);
}
