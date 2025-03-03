#ifndef pat(task9)_h
#define pat(task9)_h
#include<iostream>
#include<string>
using namespace std;
class Patient{
	public:
	string name;
	int age;
	string diesease;
	int roomNum;
	void addDetail();
	void display();
	void update(int num);
};
#endif
