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
		void insertMiddle(int d){
			int pos;
			int count=0;
			Node* newNode=new Node(d);
			cout<<"Enter index position: ";
			cin>>pos;
			Node* temp=head;
			while(temp!=NULL){
				if(count==pos-1){
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
			delete temp;
		}
		void deleteEnd(){
			Node* temp=head;
			while(temp->next->next!=NULL){
				temp=temp->next;
			}
			delete tail;
			tail=temp;
		}
		void deleteMiddle(){
			int pos;
			int count=0;
			Node* temp=head;
			cout<<"Enter index position: ";
			cin>>pos;
			while(temp!=NULL){
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
			while(temp!=NULL){
				cout<<temp->data<<"->";
				temp=temp->next;
			}
			cout<<"NULL"<<endl<<endl;
		}
		void bubbleSort(){
			Node* temp=head;
			while(temp->next!=NULL){
				Node* mov=head;
				while(mov->next!=NULL){
					Node* forward=mov->next;
					if(mov->data>forward->data){
						int temp=mov->data;
						mov->data=forward->data;
						forward->data=temp;
					}
					mov=mov->next;
				}
				temp=temp->next;
			}
		}
		void selectionSort(){
			Node* sortNode=head;
			while(sortNode!=NULL){
				Node* min=sortNode;
				Node* forward=sortNode->next;
				while(forward!=NULL){
					if(min->data>forward->data){
						min=forward;
					}
					forward=forward->next;
				}
				int temp=min->data;
				min->data=sortNode->data;
				sortNode->data=temp;
				sortNode=sortNode->next;
			}
		}
		
//		void insertionSort(){
//			Node* temp=head;
//			temp=temp->next;
//			while(temp!=NULL){
//				Node* prev=temp->prev;
//				int num=temp->data
//				while(prev!=NULL && prev->data>num){
//					temp->data=prev->data;
//					prev=prev->prev;
//				}
//				prev->next=num;
//			}
//		}
};

int main(){
	SinglyList s1;
	s1.insertEnd(11);
	s1.insertEnd(21);
	s1.insertEnd(3);
	s1.insertEnd(73);
	s1.insertEnd(10);
	s1.insertStart(91);
	s1.printNode();
//	s1.bubbleSort();
	s1.selectionSort();
	s1.printNode();
}
