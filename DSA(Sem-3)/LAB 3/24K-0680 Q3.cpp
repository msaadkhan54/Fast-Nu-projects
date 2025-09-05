#include<iostream>
using namespace std;

class Node{
	public:
	string seatStatus;
	Node* next;
	Node(string stat){
		seatStatus=stat;
		next=NULL;
	}
};

class Circularlist{
	Node* head;
	Node* tail;
	public:
	Circularlist(){
		head=NULL;
		tail=NULL;
	}
	
	void insertSeat(string stat){
		Node* newNode=new Node(stat);
		if(head==NULL){
			head=newNode;
			tail=newNode;
			tail->next=head;
		}
		tail->next=newNode;
		tail=newNode;
		tail->next=head;
	}
	
	void checkStatus(){
		if(head==NULL){
        cout<<"No seats available\n";
        return;
    }
    Node* temp=head;
    int count=0;

    do {
        if(temp->seatStatus == "empty") {
            count++;
        }
        temp=temp->next;
    }while(temp!=head);

    cout << "Total "<<count<< " seats are available" << endl;
	}
};

int main(){
	Circularlist c1;
	c1.insertSeat("empty");
	c1.insertSeat("reserved");
	c1.insertSeat("reserved");
	c1.insertSeat("empty");
	
	c1.checkStatus();
	
}
