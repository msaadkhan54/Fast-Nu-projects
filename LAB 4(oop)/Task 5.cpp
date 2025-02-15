#include <iostream>
using namespace std;
class Movie{
	private :
	string movieName;
	int availableSeats;
	double ticketPrice;
	public :
		Movie(string m,int a,double t){
			movieName=m;
			availableSeats=a;
			ticketPrice=t;
			cout<<"movie: "<<movieName<<" is available"<<endl;
		}
		void bookTicket(int seats){
			availableSeats-=seats;
			cout<<seats<<" tickets booked for "<<movieName<<" | remaining seats: "<<availableSeats<<endl;
			availableSeats-=seats;
		}
		void dispalyMovieInfo(){
			cout<<"movie name "<<movieName<<" | available seats: "<<availableSeats<<" | ticket price: "<<ticketPrice<<endl;
		}
		~Movie(){
			cout<<movieName<<" booking closed!"<<endl;
		}
};
int main(){
	Movie m1("shaka laka boom boom",50,100);
	m1.bookTicket(5);	
    m1.dispalyMovieInfo();

}
