#include<iostream>
using namespace std;

class Node{
    public:
        string value;
        int key;
        Node* next;
        Node(){
            next=NULL;
        }
        Node(string v):value(v){
            next=NULL;
            key=0;
            for(int i=0;i<v.length();i++){
                key+=value[i];
            }
        }
};

class HASH{
    Node** table;
    int size;
    public:
    HASH(){
        size=13;
        table=new Node*[size];
        for(int i=0;i<size;i++){
            table[i]=NULL;
        }
    }

    int hashVal(int key){
        return key%size;
    }

    void insert(string text){
        Node* newNode=new Node(text);
        int index=hashVal(newNode->key);
        Node* temp=table[index];
        if(temp==NULL){
            table[index] = newNode;
            return;
        }
        while(temp->next!=NULL){
            if(temp->key==newNode->key){
                temp->value=newNode->value;
                cout<<"Over write"<<endl;
                return;
            }
            temp=temp->next;
        }
        if(temp->key==newNode->key){
                temp->value=newNode->value;
                cout<<"Over write"<<endl;
                return;
        }
        temp->next=newNode;
        return;
    }

    void search(int key){
        int index=hashVal(key);
        Node*temp=table[index];
        while(temp!=NULL){
            if(temp->key==key){
                cout<<"Found at key:"<<key<<" is "<<temp->value<<endl;
                return;
            }
            temp=temp->next;
        }
        cout<<"Not Found at key:"<<key<<endl;
        return;
    }

    void remove(int key){
        int index=hashVal(key);
        Node*temp=table[index];
        Node* prev=NULL;
        while(temp!=NULL){
            if(temp->key==key){
                break;
            }
            prev=temp;
            temp=temp->next;
        }
        if(temp==NULL){
            cout<<"Not found to remove"<<endl;
            return;
        }
        if(prev==NULL){
            temp->key=-1;
            temp->value="none";
            return;
        }
        prev->next=temp->next;
        delete temp;
    }

    void print(){
        for(int i=0;i<size;i++){
            Node* temp=table[i];
            int j=0;
            if(table[i]==NULL)cout<<i+1<<":empty";
            while(temp!=NULL){
                if(j==0){
                    cout<<i+1<<":"<<temp->value;
                    j++;
                }
                else{
                    cout<<"->"<<temp->value;
                }
                temp=temp->next;
            }
            cout<<endl;
        }
    }
    ~HASH(){
        for(int i=0;i<size;i++){
            Node* temp=table[i];
            while(temp!=NULL){
                Node* del=temp;
                temp=temp->next;
                delete del;
            }
        }
        delete[] table;
        table=NULL;
    }
};

int main(){
    HASH fruit;
    fruit.insert("kiwi");
    fruit.insert("apple");
    fruit.insert("orange");
    fruit.insert("plum");
    fruit.insert("melon");
    fruit.insert("grape");
    fruit.insert("pear");
    fruit.print();
}