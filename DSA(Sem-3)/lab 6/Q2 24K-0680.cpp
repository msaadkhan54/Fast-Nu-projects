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
		
		void insertNode(int d){
			Node* newNode=new Node(d);
			if(head==NULL){
				head=newNode;
				tail=newNode;
			}
			else{
				tail->next=newNode;
				tail=newNode;	
			}
			
		}
		Node* returnHead(){
			return head;
		}
};

void printList(Node* head){
	if(head->next!=NULL){
		printList(head->next);
	}
	cout<<head->data<<endl;
	
}

int main(){
	SinglyList s1;
	s1.insertNode(1);
	s1.insertNode(2);
	s1.insertNode(3);
	s1.insertNode(4);
	s1.insertNode(5);
	s1.insertNode(6);
	s1.insertNode(7);
	printList(s1.returnHead());
	
}
