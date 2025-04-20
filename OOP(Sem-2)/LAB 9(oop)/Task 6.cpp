#include<iostream>
using namespace std;

class Shape{
	public:
		virtual void area()=0;
};

class Circle:public Shape{
	private:
		int radius;
	public:
		Circle(int rad):radius(rad){}
		void area(){
			cout<<"Area of circle with radius "<<radius<<" is "<<3.14*radius*radius<<endl;
		}
};

class Rectangle:public Shape{
	private:
		int lenght;
		int breadth;
	public:
		Rectangle(int len,int bread):lenght(len),breadth(bread){
		}
		void area(){
			cout<<"Area of Rectangle with lenght and width "<<lenght<<"x"<<breadth<<" is "<<breadth*lenght<<endl;
		}
};

class Triangle:public Shape{
	private:
		int base;
		int height;
	public:
		Triangle(int b,int h):height(h),base(b){}
		void area(){
			cout<<"Area of Triangle with base and height "<<base<<"x"<<height<<" is "<<0.5*base*height<<endl;
		}
};


int main(){
	Shape *s1[3];
	Circle c1(3);
	Rectangle r1(2,4);
	Triangle t1(3,6);
	s1[0]=&c1;
	s1[1]=&r1;
	s1[2]=&t1;
	for(int i=0;i<3;i++){
		s1[i]->area();
	}
}
