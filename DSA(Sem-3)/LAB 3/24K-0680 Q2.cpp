#include<iostream>
using namespace std;

class Node{
	public:
		string web;
		Node *next;
		Node *prev;
		
		Node(string w):web(w){
			next=NULL;
			prev=NULL;
		}
};

class DoublyList{
	Node* head;
	Node* tail;
	public:
		DoublyList(){
			head=NULL;
			tail=NULL;
		}
		
		void InsertWeb(string we){
			Node *newNode=new Node(we);
			if(head==NULL){
				head=newNode;
				tail=newNode;
			}
			else{
				tail->next=newNode;
				newNode->prev=tail;
				tail=newNode;	
			}
			
		}
		
		void previousWeb(string web){
			Node* temp=head;
			while(temp!=NULL){
				if(temp->web==web){
					Node* prev=temp->prev;
					cout<<"Previous Website to "<<web<<": "<<prev->web<<endl;
				}
				temp=temp->next;
			}
		}
		
		void forwardWeb(string web){
			Node* temp=head;
			while(temp!=NULL){
				if(temp->web==web){
					Node* forw=temp->next;
					cout<<"Forward Website to '"<<web<<"': "<<forw->web<<endl;
				}
				temp=temp->next;
			}
		}
		
		void search(string web){
			bool search=false;
			Node* temp=head;
			while(temp!=NULL){
				if(temp->web==web){
					cout<<"Website '"<<web<<"'found!"<<endl;
					search=true;
				}
				if(search){
					return;
				}
				temp=temp->next;
			}
		}
		
};

int main(){
	DoublyList d1;
	d1.InsertWeb("W3school");
	d1.InsertWeb("Choco");
	d1.InsertWeb("geeksforgeeks");
	d1.previousWeb("Choco");
	d1.forwardWeb("Choco");
	d1.search("geeksforgeeks");
}