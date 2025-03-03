#include<iostream>
using namespace std;

struct student{
	string name;
	int rollNum;
	char grades[5];
};

int main(){
	struct student s1;
	cout<<"Enter name: ";
	getline(cin,s1.name);
	cout<<"Enter roll Number: ";
	cin>>s1.rollNum;
	for(int i=0;i<5;i++){
		cout<<"Enter grade "<<i+1<<" :";
		cin>>s1.grades[i];
	}
	cout<<"The name is "<<s1.name<<endl;
	cout<<"The Roll Number is "<<s1.rollNum<<endl;
	for(int i=0;i<5;i++){
		cout<<"The grade "<<i+1<<" "<<s1.grades[i]<<endl;
	}
}