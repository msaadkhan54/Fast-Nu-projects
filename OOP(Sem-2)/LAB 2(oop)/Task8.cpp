#include<iostream>
using namespace std;

struct customer{
	string name;
	double salaryAmount;
	customer *next;
};

void create(struct customer *ptr){
		
	cout<<"Entr customer name : ";
	cin>>ptr->name;
	cout<<"Enter customer salary : ";
	cin>>ptr->salaryAmount;
	
	ptr->next=new customer;
	cout<<"Entr customer name : ";
	cin>>ptr->next->name;
	cout<<"Enter customer salary : ";
	cin>>ptr->next->salaryAmount;
	
	ptr->next->next=new customer;
	cout<<"Entr customer name : ";
	cin>>ptr->next->next->name;
	cout<<"Enter customer salary : ";
	cin>>ptr->next->next->salaryAmount;
	ptr->next->next->next=NULL;
	
}

void display(struct customer *gtr){
	cout<<"Customer name : "<<gtr->name<<endl;
	cout<<"Customer salary : "<<gtr->salaryAmount<<endl;
	
	gtr->next=new customer;
	cout<<"Customer name : "<<gtr->next->name<<endl;
	cout<<"Customer salary : "<<gtr->next->salaryAmount<<endl;
	
	gtr->next->next=new customer;
	cout<<"Customer name : "<<gtr->next->next->name<<endl;
	cout<<"Customer salary : "<<gtr->next->next->salaryAmount<<endl;

}

int main(){
	customer *c1;
	c1=new customer;
	
	create(c1);
	
	display(c1);
	
	delete c1;

	
}
