#include<iostream>
using namespace std;

class Book{
	string title;
	string author;
	float price;
	public:
		Book(){
			title="Unknown";
			author="unknown";
			price=0.0;
		}
		Book(string tit,string auth,int p){
			title=tit;
			author=auth;
			price=p;
		}
		Book(const Book &obj){
			title=obj.title;
			author=obj.author;
			price=obj.price;
		}
		void operator=(const Book &obj){
			title=obj.title;
			author=obj.author;
			price=obj.price;
		}
		~Book(){
			
		}
};

int main(){
	Book b1;
	Book b2("Alchemist","Pual",12.3);
	Book b3(b2);
}
