#include <iostream>
#include <string>
using namespace std;

class rectangle{
	private:
		double height;
		double width;
	public:
	    rectangle(double height,double width){
			this->height=height;
			this->width=width;
		}
		
		int area(){
			return height*width;
		}
};

int main(){
	double h,w;
	cout<<"enter height:";
	cin>>h;
	cout<<"enter width:";
	cin>>w;
	rectangle r(h,w);
	cout<<"area:"<<r.area();
}
