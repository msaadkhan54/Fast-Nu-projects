#include<iostream>
using namespace std;

class Car{
	private:
		string name;
		double capacity;
		double consumptionRate;
		double distance;
	public:
		Car(string n,double c,double r,double d){
			name=n;capacity=c;consumptionRate=r;distance=d;
			cout<<"Car Suzuki WagonR is ready to drive!"<<endl;
		}
		~Car(){
			cout<<"Car Suzuki WagonR is removed from tracking.";
		}
		void refuel(double liters){
			capacity+=liters;
			cout<<"Refueled "<<liters<<".Current fuel level: "<<capacity<<endl;
		}
		void display(){
			cout<<"Car: "<<name<<"| Distance driven: "<<distance<<"| fuel remaining: "<<capacity<<endl;
		}
		void drive(double dis){
			distance=dis;
			cout<<"Drove "<<distance<<"km.Remaining fuel: "<<capacity<<endl;
		}
		

};
int main(){
	Car c1("Suzuki WagonR",35,0,0);
	c1.drive(200);
	c1.refuel(0);
	c1.display();
}
