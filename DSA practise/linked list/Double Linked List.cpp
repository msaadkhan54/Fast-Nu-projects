// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node *prev;
    Node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
};

class DoubleList{
  Node* head;
  Node* tail;
  public:
    DoubleList(){
        head=NULL;
        tail=NULL;
    }
    
    void push_front(int val){
        Node *newNode=new Node(val);
        if(head==NULL){
            head=newNode;
            tail=newNode;
        }
        else{
            newNode->next=head;
            head->prev=newNode;
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
            newNode->prev=tail;
            tail=newNode;
        }
    }
    
    void pop_front(){
        Node *temp=head;
        if(temp->next==NULL){
            delete temp;
        }
        head=temp->next;
        head->prev=NULL;
        delete temp;
        
    }
    
    void pop_back(){
        Node* temp=tail;
        if(tail->prev==NULL){
           delete tail;
        }
        tail=tail->prev;
        tail->next=NULL;
        delete temp;
    }
    
    void print(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<"<=>";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
};
int main() {
    // Write C++ code here
    DoubleList Dl;
    // Dl.push_front(3);
    // Dl.push_front(2);
    // Dl.push_front(1);
    Dl.push_back(1);
    // Dl.push_back(2);
    // Dl.push_back(3);
    Dl.pop_back();
    // Dl.print();

    return 0;
}
