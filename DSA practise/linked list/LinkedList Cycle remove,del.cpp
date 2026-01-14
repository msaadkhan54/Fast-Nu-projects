// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class Node{
  public:
    int data;
    Node* next;
    Node(int val){
        next=NULL;
        data=val;
    }
};

class LinkedList{
  Node* head;
  Node* tail;
  public:
    LinkedList(){
        head=NULL;
        tail=NULL;
    }
    
    Node* push_back(int val){
        Node *newNode=new Node(val);
        Node* temp=head;
        if(head==NULL){
            head=newNode;
            tail=newNode;
            
        }
        else{
            tail->next=newNode;
            newNode->next=NULL;
            tail=newNode;
            
        }
        return newNode;
    }
    
    void print(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
    }
    
    void FindDeleteCycle(){
        Node* slow=head;
        Node* fast=head;
        bool flag=false;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                flag= true; // Cycle found
                break;
            }
        }
        
        if(!flag){
            cout<<"Nocycle;"<<endl;
        }
        else{
            slow=head;
            Node* temp;
            while(slow!=fast){
                slow=slow->next;
                temp=fast;
                fast=fast->next;
            }
            cout<<"Cycle start at "<<slow->data<<endl;
            temp->next=NULL;
            cout<<"Cycle removed"<<endl;
        }
    }
};

int main() {
    // Write C++ code here
    LinkedList LL;
    Node* one=LL.push_back(1);
    Node* two=LL.push_back(2);
    Node* three=LL.push_back(3);
    Node* four=LL.push_back(4);
    Node* five=LL.push_back(5);
    five->next=three;

    LL.FindDeleteCycle();
    LL.print();    

    return 0;
}
