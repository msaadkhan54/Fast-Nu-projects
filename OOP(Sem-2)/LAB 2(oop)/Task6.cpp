#include<iostream>
using namespace std;

struct speaker{
	string name;
	string topic;
	int timeSlot;
};

int main(){
	speaker *s1;
	s1=new speaker[4];
	for(int i=0;i<4;i++){
		cout<<"Enter the name of speaker : ";
		cin>>s1[i].name;
		
		cout<<"Enter Topic : ";
		cin>>s1[i].topic;
		
		cout<<"Enter time slot : ";
		cin>>s1[i].timeSlot;
	}
	
	for(int i=0;i<4;i++){
		cout<<"The name of speaker is "<<s1[i].name<<endl;
		
		cout<<"Topic is "<<s1[i].topic<<endl;
		
		cout<<"Time slot is "<<s1[i].timeSlot<<endl;
		cout<<endl;
	}
	delete[] s1;
}
