#include<iostream>
using namespace std;

double Area(double lenght,double width){
	return lenght * width;
}

int main(){
	double lenght,width;
	
	cout<<"Enter lenght : ";
	cin>>lenght;
	
	cout<<"Enter width : ";
	cin>>width;
	
	cout<<"The width is "<<width<<endl<<"The lenght is "<<lenght;
}