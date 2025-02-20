#include <iostream>
using namespace std;
class Movie{
	private:
		string title;
		int duration;
	public:
		Movie(string t,int d):title(t),duration(d) {}
		string get_title(){
			return title; 
		}	
		int get_duration(){
			return duration;
		}
};
class Cinema{
	private:
		Movie* x[10];
		int count;
	public:
		Cinema():count(0) {}
		void add_movie(Movie* z){
			if(count>=10){
				cout<<"Can't add any more movies"<<endl;
				return;
			}
			x[count++] = z;
		}
		void display(){
			cout<<"Currently Showing Movies:"<<endl;
			for(int i=0;i<count;i++){
				cout<<"Movie: "<<x[i]->get_title()<<" | Duration: "<<x[i]->get_duration()<<" minutes"<<endl;
			}
		}	
};
int main(){
	Movie a("Inception",148),b("Titanic",195),c("The Dark Knight",152);
	Cinema x;
	x.add_movie(&a);
	x.add_movie(&b);
	x.add_movie(&c);
	x.display();
	
}
