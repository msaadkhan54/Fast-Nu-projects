#include<iostream>
using namespace std;

struct office{
	int jobId;
	int pages;
};

class queue{
	office o[5];
	int size;
	int front;
	int rear;
	public:
		queue(){
			size=5;
			front=-1;
			rear=-1;
		}
		void push(int id,int pag){
			if(front==-1){
				front++;
				rear++;
				cout<<"New Order of printing "<<pag<<" from Job ID: "<<id<<endl;
				o[rear].jobId=id;
				o[rear].pages=pag;
				return;
			}
			else if(front==(rear+1)%size){
				cout<<"Sorry for inconvinence, as orders exceeded the limit"<<endl;
				return;
			}
			cout<<"New Order of printing "<<pag<<" from Job ID: "<<id<<endl;
			rear=(rear+1)%size;
			o[rear].jobId=id;
			o[rear].pages=pag;
				
		}
		void pop(){
			if(front==-1){
				cout<<"All orders are completed already"<<endl;
				return;
			}
			if(front==rear){
				cout<<o[front].pages<<" pages are PRINTED of Job ID: "<<o[front].jobId<<endl;
				front=-1;
				rear=-1;
				return;
			}
			cout<<o[front].pages<<" pages are PRINTED of Job ID: "<<o[front].jobId<<endl;
			front++;
		}
		bool isEmpty(){
			return front==-1;
		}
};
int main(){
	queue q1;
	q1.push(12,344);
	q1.push(101,42);
	q1.push(201,57);
	q1.push(002,34);
	q1.push(032,80);
	q1.push(598,100);
	q1.pop();
	q1.pop();
	q1.pop();
	q1.pop();
	q1.pop();
	q1.pop();
}
