#include<iostream>
using namespace std;
class Node{
	public:
		int data;
		Node *next;
		Node(int d){
			data=d;
			next=NULL;
		}
};

class CircularList{
	Node* head;
	Node* tail;
	public:
		CircularList(){
			head=NULL;
			tail=NULL;
		}
		void insertEnd(int d){
			Node* newNode=new Node(d);
			if(head==NULL){
				head=newNode;
				tail=newNode;
				return;
			}
			tail->next=newNode;
			tail=newNode;
			tail->next=head;
		}
		void insertStart(int d){
			Node* newNode=new Node(d);
			if(head==NULL){
				head=newNode;
				tail=newNode;
				return;
			}
			newNode->next=head;
			head=newNode;
			tail->next=head;
		}
		void insertMiddle(int d){
			int pos;
			int count=0;
			Node* newNode=new Node(d);
			cout<<"Enter index position: ";
			cin>>pos;
			Node* temp=head;
			if(pos==count){
				newNode->next=head;
				head=newNode;
				tail->next=head;
				return;
			}
			else{
				temp=temp->next;
			}
			while(temp!=head){
				if(count==pos-2){
					newNode->next=temp->next;
					temp->next=newNode;
					return;
				}
				temp=temp->next;
				count++;
			}
		}
		void deleteStart(){
			Node* temp=head;
			head=head->next;
			tail->next=head;
			delete temp;
		}
		void deleteEnd(){
			Node* temp=head;
			while(temp->next->next!=NULL){
				temp=temp->next;
			}
			delete tail;
			tail=temp;
			tail->next=head;
		}
		void deleteMiddle(){
			int pos;
			int count=0;
			Node* temp=head;
			cout<<"Enter index position: ";
			cin>>pos;
			if(pos==0){
				head=head->next;
				tail->next=head;
				delete temp;
				return;
			}
			else{
				temp=temp->next;
			}
			while(temp!=head){
				Node* prev;
				if(count==pos){
					prev->next=temp->next;
					delete temp;
					return;
				}
				prev=temp;
				temp=temp->next;
				count++;
			}
		}
		void printNode(){
			Node* temp=head;
			cout<<temp->data<<"->";
			temp=temp->next;
			while(temp!=head){
				cout<<temp->data<<"->";
				temp=temp->next;
			}
			cout<<"NULL"<<endl<<endl;
		}
};

int main(){
	CircularList s1;
	s1.insertEnd(1);
	s1.insertEnd(2);
	s1.insertEnd(3);
	s1.insertStart(0);
	s1.insertMiddle(4);
	s1.printNode();
	s1.deleteMiddle();
	s1.printNode();
}
