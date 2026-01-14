#include<iostream>
using namespace std;
class Node{
	public:
		char c;
		Node* next;
		Node(char d):c(d){next=NULL;} 
};
class Stack{
	public:
		Node* head;
		int siz;
		Stack(){
			head=NULL;siz=0;
		}
		void push(char c){
			Node* newNode=new Node(c);
			siz++;
			if(head==NULL){
				head=newNode;
				return;
			}
			newNode->next=head;
			head=newNode;
		}
		
		void pop(){
			if(head==NULL){
				return;
			}
			
			siz--;
			Node* temp=head;
			head=head->next;
			delete temp;
		}
		
		char top(){
			return head->c;
		}
		int size(){
			return siz;
		}
		bool isEmpty(){
			return siz==0;
		}
};

int main(){
	string text;
	cout<<"Enter string: ";
	cin>>text;
	int mid=-1;
	Stack s;
	if(text.size()%2!=0)
	mid=text.size()/2;
	
	for(int i=0;i<text.size();i++){
		if(mid==i)continue;
		if(!s.isEmpty() && s.top()==text[i]) s.pop();
		else{s.push(text[i]);}
	}
	if(s.isEmpty()){
		cout<<"string is palindrome";
	}
	else{
		cout<<"string is not a palindrome";
	}
}
