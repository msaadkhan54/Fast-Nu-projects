// Online C++ compiler to run C++ program online
#include <iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int n){
        data=n;
        left=right=NULL;
    }
};
Node* createNode(int d){
	return new Node(d);
}

    Node* insert(Node* root,int n){
        if(root==NULL){
            return new Node(n);
        }
        if(root->data>n){
            root->left=insert(root->left,n);
        }
        if(root->data<n){
            root->right=insert(root->right,n);
        }
        return root;
    }
    Node* successive(Node* root){
        while(root->left!=NULL){
            root=root->left;
        }
        return root;
    }
    Node* deleteNode(Node* root,int n){
        if(root==NULL)return NULL;
        if(root->data>n){
            root->left=deleteNode(root->left,n);
        }
        else if(root->data<n){
            root->right=deleteNode(root->right,n);
        }
        else{
            if(root->left==NULL){
                Node* temp=root->right;
                delete root;
                return temp;
            }
            else if(root->right==NULL){
                Node* temp=root->left;
                delete root;
                return temp;
            }
            else{
                Node* temp=successive(root->right);
                root->data=temp->data;
                root->right=deleteNode(root->right,temp->data);
                return root;
            }
        }
        return root;
    }
    void levelOrder(Node* root){
        queue<Node*> q1;
        q1.push(root);
        q1.push(NULL);
        while(!q1.empty()){
            Node* temp=q1.front();
            q1.pop();
            cout<<temp->data<<" ";
            if(temp==NULL){
                cout<<endl;
            }
            else{
                q1.push(temp->left);
                q1.push(temp->right);
            }
        }
    }
int main() {
    Node* root=createNode(4);
    insert(root,2);
    insert(root,1);
    insert(root,9);
    insert(root,6);
    insert(root,10);
    insert(root,5);
    insert(root,7);
    levelOrder(root);

    return 0;
}