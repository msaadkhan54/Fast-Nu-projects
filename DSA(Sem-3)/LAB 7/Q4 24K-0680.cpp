#include<iostream>
using namespace std;

class Node{
	public:
		static int count;
		int serial;
		Node* next;
		Node(){
			next=NULL;
			count++;
			serial=count;
		} 
};
int Node::count=0;

class Queue{
	public: 
		Node* head;
		Node* tail;
		
		Queue(){
			head=NULL;
			tail=NULL;
		}
		void addLine(){
			Node* newNode=new Node();
			cout<<"This person is "<<newNode->count<<" customer"<<endl;
			if(head==NULL){
				head=newNode;
				tail=newNode;
			}
			tail->next=newNode;
			tail=newNode;
		}
		
		void serve(){
			if(head==NULL){
				return;
			}
			Node* temp=head;
			cout<<"Person "<<temp->serial<<" purchased the ticket"<<endl;
			if(head==tail){
				head=NULL;
				tail=NULL;
				cout<<"No customer in Queue"<<endl;
			}
			head=head->next;
			delete temp;	
		}
		int top(){
			return head->count;
		}
};

int main(){
	Queue q;
	q.addLine();
	q.addLine();
	q.addLine();
	q.serve();
	q.serve();
	q.addLine();
	q.serve();
}
