// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
class Node{
	public:
		long long int data;
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
		void insertEnd(long long int d){
			Node* newNode=new Node(d);
			if(head==NULL){
				head=newNode;
				tail=newNode;
				return;
			}
			tail->next=newNode;
			tail=newNode;
		}
		void printNode(){
			Node* temp=head;
			while(temp!=NULL){
				cout<<temp->data<<"->";
				temp=temp->next;
			}
			cout<<"NULL"<<endl<<endl;
		}
		Node* getHead(){
		    return head;
		}
};


void sortLinkedlist(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        Node* unSort=temp->next;
        Node* smallest=temp;
        while(unSort!=NULL){
            if(smallest->data>unSort->data){
                smallest=unSort;
            }
            unSort=unSort->next;
        }
        long long int num=temp->data;
        temp->data=smallest->data;
        smallest->data=num;
        temp=temp->next;
    }
}

int main() {
    SinglyList s1;
    s1.insertEnd(125432);
    s1.insertEnd(765964);
    s1.insertEnd(2347327);
    s1.insertEnd(642948297);
    s1.insertEnd(975444);
    s1.insertEnd(4790000);
    s1.insertEnd(53267731);
    s1.printNode();
    cout<<endl<<"Sorted:"<<endl;
    sortLinkedlist(s1.getHead());
    s1.printNode();
    

    return 0;
}
