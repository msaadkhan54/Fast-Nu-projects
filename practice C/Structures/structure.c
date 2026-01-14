#include<stdio.h>
#include<string.h>

typedef struct author{
	char firstName[10];
	char middleName[10];
	char lastName[10];
} auth;

typedef struct libaray{
	int accession;
	char title[20];
    auth name;
	float price;
	int flag;
} lib ;

int main(){
	lib data={1234,"shutup",{""},1200.50,1};
	strcpy(data.name.firstName, "Muhammad");
    strcpy(data.name.middleName, "Saad");
    strcpy(data.name.lastName, "Khan");
	printf("%d\n",data.accession);
	printf("%s\n%s %s %s\n",data.title,data.name.firstName,data.name.middleName,data.name.lastName);
	printf("%.2f\n",data.price);
	if(data.flag)
	printf("Issued.");
	else printf("not issued");
}   
