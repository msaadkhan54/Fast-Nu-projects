#include<iostream>
using namespace std;

struct student{
	string name;
	int rollNumber;
	int year;
	int grades[5];
};

void highestMarks(struct student *ptr){
	int sum;
	int temp=0;
	int high=0;
	for(int i=0;i<5;i++){
		sum=0;
		for(int j=0;j<5;j++){
			sum+=ptr[i].grades[j];
		}
		if (sum>temp){
		high=i;
		temp=sum;
	}
	}
	cout<<"The student "<<ptr[high].name <<" ("<<high+1<<") got the highest marks in exam";
}

int main(){
	struct student *s1;
	s1 = new student[5];
	
//	cin.ignore();
	for(int i=0;i<5;i++){
		cout<<"Enter name for student "<<i+1<<" : ";
		getline(cin,s1[i].name);
		
		cout<<"Enter roll number for student "<<i+1<<" : ";
		cin>>s1[i].rollNumber;
		
		cout<<"Enter YEAR for student "<<i+1<<" : ";
		cin>>s1[i].year;
		
		cout<<"STUDENT "<<i+1<<":"<<endl;
		for(int j=0;j<5;j++){
			cout<<"Enter grade marks(out of 100) "<<j+1<<" : ";
			cin>>s1[i].grades[j];
		}
		cin.ignore();
		cout<<endl;
	}
	highestMarks(s1);
	
	delete[] s1;
	
	
}
