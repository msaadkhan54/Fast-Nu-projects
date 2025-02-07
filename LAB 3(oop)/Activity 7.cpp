#include<iostream>
using namespace std;

class Shape{
	double lenght,width;
	
	public:
		Shape(double l,double w) : lenght(l),width(w){};
		
		void setLen(double len){
			lenght=len;
		}
		double getLen(){
			return lenght;
		}
		
		void setWid(double wid){
			width=wid;
		}
		double getWid(){
			return width;
		}
};

int main(){
	int len,wid;
	Shape s1(23.4,43.2);
	cout<<"The lenght of 1 is "<<s1.getLen()<<".  The width of 1 is "<<s1.getWid()<<endl;
	cout<<"Enter lenght and width respectively :";
	cin>>len>>wid;
	Shape s2(len,wid);

	cout<<"The lenght of 1 is "<<s2.getLen()<<".  The width of 1 is "<<s2.getWid();
}