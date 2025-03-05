#include<iostream>
using namespace std;
class Libraryitem{
	public:
		string name;
		string author;
		
};

class Books:public Libraryitem{
	public:
		long int ISBN;
		Books(string t,string a,long int i){
			name=t; author=a; ISBN=i;
		}
		void display(){
			cout<<"  === Book Details ==="<<endl;
			cout<<"Title: "<<name<<endl;
			cout<<"Author: "<<author<<endl;
			cout<<"ISBN: "<<ISBN<<endl<<endl;
		}
};

class Magazine:public Libraryitem{
	public:
		int issueNumber;
		Magazine(string t,string a,int i){
			name=t; author=a; issueNumber=i;
		}
		void display(){
			cout<<"  === Magazine Details ==="<<endl;
			cout<<"Title: "<<name<<endl;
			cout<<"Author: "<<author<<endl;
			cout<<"Issue number: "<<issueNumber<<endl<<endl;
		}
};

int main(){
	Books b1("The Great Gatsby","F. Scott Fitzgerald",53859935);
	b1.display();
	Magazine m1("National Geographic","Multiple Authors",202);
	m1.display();
}

