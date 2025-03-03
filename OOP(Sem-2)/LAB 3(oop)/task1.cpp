#include <iostream>
#include <string>
using namespace std;

class car{
	private:
		string model;
		int year;
		string brand;
	public:
		car(string model,int year,string brand){
			this->model=model;
			this->year=year;
			this->brand=brand;
		}
		
		void display(){
			cout<<"model:"<<model<<endl;
			cout<<"year:"<<year<<endl;
			cout<<"brand:"<<brand;
		}
};

int main(){
	car c("wagonar",2020,"suzuki");
	c.display();
}
