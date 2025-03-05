#include<iostream>
using namespace std;

class Base{
	public:
	int i;
	int b;
		Base(int i,int b){
			this->i=i;
			this->b=b;
		}
};

class derived1:public Base{
	public:
		int j,c;
		derived1(int i,int b,int j,int c) : Base(i,b){
			this->j=j;
			this->c=c;
		}
		void showData1(){
			cout<<"i= "<<i<<endl<<"b= "<<b<<endl;
		}
};

class derived2: public derived1{
	public:
	derived2(int i,int b,int j,int c):derived1(i,b,j,c){
	}
	void showData2(){
			cout<<"j= "<<j<<endl<<"c= "<<c;
		}
};

int main(){
	derived2 d1(4,5,6,7);
	d1.showData1();
	d1.showData2();
}
