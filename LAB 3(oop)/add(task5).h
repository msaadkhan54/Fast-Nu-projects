#ifndef add(task5)_h
#define add(task5)_h

#include<iostream>
#include<string>
using namespace std;

class Books{
	public:
		string title;
		string author;
		long int ISBN;
		bool isAvailable;
		void display(){
			cout<<"The title is "<<title<<endl;
			cout<<"\nThe author is "<<author<<endl;
			cout<<"\nThe ISBN is "<<ISBN<<endl;
			cout<<"Availability :  "<<isAvailable<<endl<<endl;
		}
		void update_status(void);
		void addBook(void);
		void searchBook();

};
#endif
