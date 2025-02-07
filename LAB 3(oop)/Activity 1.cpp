#include<iostream>
using namespace std;

class Student{
	int rollNum;
	
	public:
		void set_roll(int roll){
			rollNum=roll;
		}
		
		int get_roll(){
			return rollNum;
		}
};

int main(){
	Student s1;
	int num;
	cout<<"Enter roll number : ";
	cin>>num;
	s1.set_roll(num);
	cout<<"The roll num is "<<s1.get_roll();
}