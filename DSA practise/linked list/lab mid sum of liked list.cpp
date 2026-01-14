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

class SinglyList{
	Node* head;
	Node* tail;
	public:
		SinglyList(){
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
		}
		void printNode(){
			Node* temp=head;
			while(temp!=NULL){
				cout<<temp->data<<"->";
				temp=temp->next;
			}
			cout<<"NULL"<<endl<<endl;
		}
		void setHead(Node* temp){
			head=temp;
		}
		Node* getHead(){
			return head;
		}
};

void sumLinkedlist(Node* temp1,Node* temp2){
	int num1=0;
	int num2=0;
	while(temp1!=NULL){
		num1+=temp1->data;
		num1*=10;
		temp1=temp1->next;
	}
	while(temp2!=NULL){
		num2+=temp2->data;
		num2*=10;
		temp2=temp2->next;
	}
	int num3=num1+num2;
	
	
	long long int divide=1000000;
	int rem=num3/divide;
	Node* newNode=new Node(rem);
	Node* head=newNode;
	Node* prev=newNode;
	divide/=10;
	while(divide>1){
	    rem=num3/divide;
	    rem%=10;
		Node* newNode=new Node(rem);
		prev->next=newNode;
		prev=newNode;
		divide/=10;
	}
	SinglyList s3;
	s3.setHead(head);
	s3.printNode();
	
}

int main(){
	SinglyList s1;
	s1.insertEnd(1);
	s1.insertEnd(3);
	s1.insertEnd(4);
	s1.insertEnd(7);
	
	SinglyList s2;
	s2.insertEnd(1);
	s2.insertEnd(9);
	s2.insertEnd(9);
	s2.insertEnd(8);
	s2.insertEnd(4);
	s2.insertEnd(7);
	sumLinkedlist(s1.getHead(),s2.getHead());
}
