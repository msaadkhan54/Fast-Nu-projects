#include<iostream>
using namespace std;

class Temprature{
	double celcius;
	public:
		Temprature(double celcius){
			this->celcius=celcius;
		}
		~Temprature(){
			cout<<"Object destroyed"<<endl;
		}
		toFarenhite(){
			int far= celcius* (9/5) + 32;
			cout<<" | "<<"Farenhite: "<<far<<"F"<<" | ";
		}
		toKelvin(){
			int kel=celcius + 273.15;
			cout<<"Kelvin: "<<kel<<"K"<<endl;;
		}
		void displayTemprature(){
			cout<<"Temperature object created with "<<celcius<<" C"<<endl<<"Celcius: "<<celcius<<"C ";
		}
};

int main(){
	Temprature t1(25);
	t1.displayTemprature();
	t1.toFarenhite();
	t1.toKelvin();	
}
