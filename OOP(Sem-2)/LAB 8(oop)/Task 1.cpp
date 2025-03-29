#include<iostream>
using namespace std;
class AreaCalculator;
class Rectangle{
	int lenght;
	int width;
	public:
		Rectangle(int l,int w){
			lenght=l;
			width=w;
		}
	friend AreaCalculator;
};

class AreaCalculator{
	public:
		int CalculateArea(Rectangle &r1);
};

int AreaCalculator::CalculateArea(Rectangle &r1){
	int area;
	area=r1.lenght*r1.width;
	return area;
}
int main(){
	Rectangle r1(4,5);
	AreaCalculator a1;
	int area=a1.CalculateArea(r1);
	cout<<"AREA: "<<area;
}
