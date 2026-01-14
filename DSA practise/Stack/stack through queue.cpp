#include<iostream>
#include<queue>
using namespace std;

class Stack{
	queue<int> q1;
	queue<int> q2;
	public:
		void push(int data){
			while(!q1.empty()){
				q2.push(q1.front());
				q1.pop();
			}
			q1.push(data);
			while(!q2.empty()){
				q1.push(q2.front());
				q2.pop();
			}
		}
		void pop(){
			q1.pop();
		}
		
		int top1(){
			return q1.front();
		}
};

int main(){
	Stack s1;
	s1.push(12);
	s1.push(32);
	s1.push(1);
	cout<<s1.top1()<<endl;
	s1.pop();
	cout<<s1.top1()<<endl;
	s1.pop();
	cout<<s1.top1()<<endl;
}
