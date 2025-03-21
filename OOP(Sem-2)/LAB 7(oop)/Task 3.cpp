#include<iostream>
#include<cstring>
using namespace std;
class String{
	char *arr;
	public:
		String(){}
		String(string c){
			arr=new char[c.length()];
			strcpy(arr, c.c_str()); 
		}
		String operator+(const String &obj){
			String temp;
			temp.arr=new char[strlen(arr)+strlen(obj.arr)+1];
			strcpy(temp.arr,arr);
			strcat(temp.arr,obj.arr);
			return temp;
		}
		
		void operator==(const String &obj){
			if(strcmp(arr,obj.arr)==0){
				cout<<"Strings are Equal: Yes"<<endl;
			}
			else{
				cout<<"Strings are Equal: No"<<endl;
			}
		}
		
		void display(){
			cout<<arr<<endl;
		}
		~String(){
			delete[] arr;
		}
};

int main(){
	String s1("Hello");
	String s2("World");
	String s3=s1+s2;
	s3.display();
	String s4("saad");
	 s4==s1;
}
