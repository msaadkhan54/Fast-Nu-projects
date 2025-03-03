#include<iostream>
using namespace std;

class Toyota{
	private:
		string model;
		int year;
		string color;
	
	public:
		
		Toyota(string model,int year,string color){
			this->model=model;
			this->year=year;
			this->color=color;
		}
		void display(){
			cout<<"Model : "<<model<<endl;
			cout<<"Year : "<<year<<endl;
			cout<<"Color : "<<color<<endl;
		}
		
};

int main(){
	Toyota t1("6 generation",2024,"white");
	t1.display();
}