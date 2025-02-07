#include<iostream>
using namespace std;

class Student{
	public:
	string name;
	int rollNum;
	int marks[5];
	int totalMarks;
	float percentage;
	char grade;
	
	void inputDetails(){
		cout<<"Enter name : ";
		cin>>name;
		cout<<"Enter roll number : ";
		cin>>rollNum;
		for(int i=0;i<5;i++){
			cout<<"Enter Marks "<<i+1<<" : ";
			cin>>marks[i];
		}
	}
	
	void calculateGrade(){
		int total=0;
		for(int i=0;i<5;i++){
			total+=marks[i];
		}
		totalMarks=total;
		percentage=total/5;
		if (percentage>=90){
			grade='A';
	    }
		else if (percentage>=80){
			grade='B';
		}
		else if (percentage>=70){
			grade='C';
		}
		else if (percentage>=60){
			grade='D';
		}
		else{
			grade='E';
		}
	}
	void displayReportCard(){
		cout<<"Name : "<<name<<endl;
		cout<<"RollNum : "<<rollNum<<endl;
		for(int i=0;i<5;i++){
			cout<<"Marks "<<i+1<<" : "<<marks[i]<<endl;
		}
		cout<<"Total Marks : "<<totalMarks<<endl;
		cout<<"Percentage : "<<percentage<<endl;
		cout<<"Grade : "<<grade<<endl;
		
	}
	
};

int main(){
	Student s1;
	s1.inputDetails();
	s1.calculateGrade();
	s1.displayReportCard();
}
