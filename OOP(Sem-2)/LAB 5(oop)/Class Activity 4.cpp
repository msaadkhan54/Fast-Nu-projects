#include<iostream>
using namespace std;

class Printer{
	string model;
	static string printMode;
	public:
		Printer(string m): model(m){
		}
		
		void getprinterInfo() const{
//			printMode="Black and white";  Static variable can be changed in const function but it cannot make change in any other sttributes
			cout<<"Printer model "<<model<<",Mode: "<<printMode<<endl;;
		}
		
		static void setprintMode(string mode){
			printMode=mode;
		}
};

string Printer::printMode="Color";

int main(){
	Printer p1("Hp laser");
	Printer p2("Canon Pixma");
	
	p1.getprinterInfo();
	Printer::setprintMode("Canon pixma 3222");
	p2.getprinterInfo();
}
