#include<iostream>
#include<fstream>
using namespace std;

int main(){
	ifstream file("debug.txt");
	int temp;
	cout<<"Enter the position of cursor in FILE: ";
	cin>>temp;
	
	file.seekg(temp,ios::beg);
	streampos position=file.tellg();
	cout<<"Pointer position before: "<<position<<endl<<endl;
	int count=0;
	char ch;
	while(count<99){
		count++;
		file.get(ch);
		cout<<ch;
	}
	position=file.tellg();
	cout<<endl<<"\nPointer position after: "<<position<<endl;
}
