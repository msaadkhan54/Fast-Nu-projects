#include<iostream>
using namespace std;

struct library{
	string name;
	string author;
	long int ISBN;
	int avail;
};

int main(){
	library *s1;
	s1=new library[3];
	for(int i=0;i<3;i++){
		cout<<"Enter the name of BOOK : ";
		cin>>s1[i].name;
		
		cout<<"Enter AUTHOR : ";
		cin>>s1[i].author;
		
		cout<<"Enter ISBN : ";
		cin>>s1[i].ISBN;
		
		cout<<"Enter availibilty(0 or 1) : ";
		cin>>s1[i].avail;
	}
	
	for(int i=0;i<3;i++){
		cout<<"The name of BOOK is "<<s1[i].name<<endl;
		
		cout<<"Author is "<<s1[i].author<<endl;
		
		cout<<"ISBN is "<<s1[i].ISBN<<endl;
		
		cout<<"The availibilty is "<<s1[i].avail;
		cout<<endl<<endl;
	}
	delete[] s1;
}
