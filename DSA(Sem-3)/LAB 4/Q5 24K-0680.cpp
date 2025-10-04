#include<iostream>
using namespace std;

class Node{
	public:
		int sal;
		Node* next;
		Node(int s):sal(s){
			next=NULL;
		}
};

class linkedList{
	Node* head;
	Node* tail;
	public:
		linkedList(){
			head=NULL;
			tail=NULL;
		}
		void insertNodeEnd(int s){
			Node* newNode=new Node(s);
			if(head==NULL){
				head=newNode;
				tail=newNode;
			}
			tail->next=newNode;
			tail=newNode;
		}
		void insertNodeStart(int s){
			Node* newNode=new Node(s);
			if(head==NULL){
				head=newNode;
				tail=newNode;
			}
			newNode->next=head;
			head=newNode;
		}
		void printNode(){
			Node* temp=head;
			while(temp!=NULL){
				cout<<temp->sal<<"->";
				temp=temp->next;
			}
			cout<<"NULL"<<endl;
		}
		Node* returnHead(){
			return head;
		}
};

void selectionSort(Node* curr){
	while(curr!=NULL){
		Node* min=curr;
		Node* forward=min->next;
		while(forward!=NULL){
			if(min->sal>forward->sal){
				min=forward;
			}
			forward=forward->next;
		}
		int temp=curr->sal;
		curr->sal=min->sal;
		min->sal=temp;
		curr=curr->next;
	}
}

int main(){
	linkedList l1;
	l1.insertNodeStart(1200);
	l1.insertNodeStart(1300);
	l1.insertNodeStart(543);
	l1.insertNodeEnd(2345);
	l1.insertNodeEnd(876);
	l1.insertNodeEnd(980);
	cout<<"Before Sorting: "<<endl;
	l1.printNode();
	selectionSort(l1.returnHead());
	cout<<"After Sorting: "<<endl;
	l1.printNode();
}
