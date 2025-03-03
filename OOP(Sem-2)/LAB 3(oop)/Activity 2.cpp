#include<iostream>
using namespace std;

class Rectangle{
	int height,width;
	
	public:
		void setHeight(int h){
			height=h;
		}
		int getHeight(){
			return height;
		}
		
		void setWidth(int w){
			width=w;
		}
		int getWidth(){
			return width;
		}
};

int main(){
	Rectangle r1;
	int height,width;
	cout<<"Enter the height of rectangle : ";
	cin>>height;
	cout<<"Enter the width of rectangle : ";
	cin>>width;
	r1.setHeight(height);
	r1.setWidth(width);
	cout<<"The height slected is "<<r1.getHeight()<<endl;
	cout<<"The width selected is "<<r1.getWidth()<<endl;
	
}