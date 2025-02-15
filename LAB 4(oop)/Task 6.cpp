#include <iostream>
using namespace std;

class devices{
	private:
		string name;
		string type;
		double rating;
		double hour;
	public:
		devices(string n,string t,double r,double h){
			name=n;
			type=t;
			rating=r;
			hour=h;
			cout<<name<<"("<<type<<")"<<" is active!"<<endl;
		}
		void use(double h){
			hour+=h;
		}
		int energy(){
			return rating*hour/1000;
		}
		void display(){
			cout<<name<<" | "<<"type: "<<type<<" | power: "<<rating<<"W | hours used: "<<hour<<" | energy consumed: "<<energy()<<endl;
			
		}
		~devices(){
			 cout<<name<<"("<<type<<")"<<" has been removed from tracking!"<<endl;
		}
};
int main(){
	devices x("smart heater","heater",45.8,78.0);
	devices y("smart ac","ac",40.9,28.0);
	x.display();
	y.display();
}
