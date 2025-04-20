#include<iostream>
using namespace std;

class Animal{
	public:
		virtual void makesound()=0;
};

class Dog:public Animal{
	public:
		void makesound(){
			cout<<"Dog Barks"<<endl;
		}
};

class Cat:public Animal{
	public:
		void makesound(){
			cout<<"Meow meow"<<endl;
		}	
};

class Cow:public Animal{
	public:
		void makesound(){
			cout<<"mooo mooo"<<endl;
		}
};

int main(){
	Animal *animal[3];
	
	Cat c1;
	Dog d1;
	Cow cow;
	
	animal[0]=&c1;
	animal[1]=&d1;
	animal[2]=&cow;
	
	for(int i=0;i<3;i++){
		animal[i]->makesound();
	}
}
