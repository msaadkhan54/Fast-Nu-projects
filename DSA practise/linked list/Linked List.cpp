// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
class Node{
    public:
        int data;
        Node *next;
        
        Node(int val){
            data=val;
        }
};

class List{
    Node *head;
    Node *tail;
    public:
        List(){
            head=NULL;
            tail=NULL;
        }
        
        void push_front(int val){
            Node *newNode=new Node(val);
            if(head==NULL ){
                head=newNode;
                tail=newNode;
            }
            else{
                newNode->next=head;
                head=newNode;
            }
        }
        
        void printNode(){
            Node *temp=head;
            while(temp!=NULL){
                cout<<temp->data<<"->";
                temp=temp->next;
                
            }
        }
        
        void push_back(int val){
            Node *newNode=new Node(4);
            if(head==NULL){
                head=newNode;
                tail=newNode;
            }
            else{
                tail->next=newNode;
                tail=newNode;
            }
        }
        
        void pop_front(){
            Node *temp=head;
            head=head->next;
            temp->next=NULL;
            delete temp;
        }
        void pop_back(){
            if(head==NULL)
                return;
            Node *temp=head;
            while(temp->next!=tail){
                temp=temp->next;
            }
            temp->next=NULL;
            delete tail;
        }
};
    

int main() {
    List LL;
    LL.push_front(1);
    LL.push_front(2);
    LL.push_front(3);
    LL.push_back(4);
    LL.pop_front();
    LL.pop_back();
    LL.printNode();
    

    return 0;
}
