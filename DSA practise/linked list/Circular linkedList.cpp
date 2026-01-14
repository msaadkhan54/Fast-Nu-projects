// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
class Node{
  public:
  int data;
  Node* next;
  Node(int val):data(val){
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
    
    void push_front(int val){
        Node* newNode=new Node(val);
        if(head==NULL){
            head = tail = newNode;
            tail->next = newNode;
        }
        else{
            tail->next=newNode;
            newNode->next=head;
            head=newNode;
            
        }
    }
    
    void push_back(int val){
        Node* newNode=new Node(val);
        if(head==NULL){
            head=newNode;
            tail=newNode;
        }
        else{
            tail->next=newNode;
            tail=newNode;
            tail->next=head;
        }
        
    }
    
    void pop_front(){
        Node* temp;
        if(head==NULL){
            return;
        }
        else if(head==tail){
            delete head;
        }
        else{
            tail->next=head->next;
            head->next=NULL;
            temp=head;
            head=tail->next;
            delete temp;
        }
    }
    
    void pop_back(){
        Node* temp=head;
        if (head==NULL){
            return;
        }
        else if(head==tail){
            delete head;
        }
        else{
            Node* temp1=tail;
            while(temp->next!=tail){
                temp=temp->next;
            }
            temp->next=head;
            tail->next=NULL;
            tail=temp;
            delete temp1;
        }
    }
    
    void print(){
        Node* temp=head;
        cout<<head->data<<"->";
        temp=temp->next;
        while(temp!=head){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<temp->data<<"(head)"<<endl;
    }
    
};

int main() {
    CircularList CL;
    CL.push_front(3);
    CL.push_front(2);
    CL.push_front(1);
    CL.push_back(4);
    CL.pop_front();
    CL.pop_back();
    CL.print();

    return 0;
}
