#include<stdio.h>
struct chocolate{
	char name[50];
	float weight;
	int calories;
	float price;
	char expiryDate[20];
};
int main(){
	struct chocolate myfav[3];
	for(int i=0;i<3;i++){
		printf("Enter chocolate name\n");
		scanf("%s", myfav[i].name);
		printf("Enter chocolate wieght\n");
		scanf("%f", &myfav[i].weight);
		printf("enter chocolate calories\n");
		scanf("%d",&myfav[i].calories);
		printf("%d Enter Chocolate price\n");
		scanf("%f",&myfav[i].price);
		printf("Enter expiry date\n");
		scanf("%s",myfav[i].expiryDate);
	}
	for(int i=0;i<3;i++)
	{
		printf("chocolate %d\n:",i+1);
		printf("name: %s\n",myfav[i].name);
		printf("Weight:%.2f\n",myfav[i].weight);
		printf("calories: %d\n",myfav[i].calories);
		printf("price:%.2f\n",myfav[i].price);
		printf("expiry date:%s",myfav[i].expiryDate);
	}
	return;
}