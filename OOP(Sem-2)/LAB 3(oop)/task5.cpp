#include<iostream>
#include"add(task5).h"
using namespace std;

void Books::update_status(void){
	int up;
		cout<<"Enter 1 or 0 : ";
		cin>>up;
		if (up==1)
			isAvailable=true;
		else 
			isAvailable=false;
}

void Books::addBook(void){
	cout << "Enter Book Title: ";
    getline(cin, title);
    
    cout << "Enter Author Name: ";
    getline(cin, author);
    
    cout << "Enter ISBN Number: ";
    cin>>ISBN;
    
    isAvailable = true;
    cout << "Book Added Successfully!" << endl;
    cin.ignore();
}

void Books :: searchBook(){
	cout<<"The TITLE is "<<title<<endl;
	cout<<"\nThe author is "<<author<<endl;
	cout<<"\nThe ISBN is "<<ISBN<<endl;
	cout<<"Availability : "<<isAvailable<<endl<<endl;
}

int main(){
	int num,index,a;
	Books b1[3];
	for(int i=0;i<3;i++){
		b1[i].addBook();
	}
	
	cout<<"Enter index to update status : ";
	cin>>a;
	
	b1[a].update_status();
	b1[a].display();
	cout<<"Enter book index for search : ";
	cin>>index;
	for(int i=0;i<3;i++){
		if(index==i){
			b1[i].searchBook();
		}
	}
}
