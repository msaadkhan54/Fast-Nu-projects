#include<iostream>
using namespace std;

class DigitalClock{
	private:
		int hours;
		int minutes;
	public:
		DigitalClock(){
			hours=7;
			minutes=30;
		}
		void display(){
			cout<<"Current Time: "<<hours<<":"<<minutes<<" AM"<<endl;
		}
		~DigitalClock(){
			cout<<"Digital Clock Destroyed!";
		}
};

int main(){
	DigitalClock clock;
	clock.display();
}
