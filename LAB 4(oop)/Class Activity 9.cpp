#include<iostream>
using namespace std;

class Rectangle{
	private:
		int lenght;
		int width;
	public:
		Rectangle(int l,int w): lenght(l),width(w){
			cout<<"Rectangle object created with lenght = "<<lenght<<" and width = "<<width<<endl;
		}
		int area(){
			return lenght * width;
		}
		~Rectangle(){
			cout<<"Rectangle object destroyed"<<endl;
		}
};

int main(){
	Rectangle rect(5,10);
	cout<<"Area of rectangle: "<<rect.area()<<endl;
}
