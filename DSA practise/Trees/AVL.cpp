// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int d){
        data=d;
        left=right=NULL;
    }
};

int height(Node* root){
    if(root==NULL){
        return 0;
    }
    int left=height(root->left);
    int right=height(root->right);
    return max(left,right)+1;
}

class AVL{
    public:
    Node* insertNode(Node* root,Node* input){
        if(root==NULL){
            return new Node(input->data);
        }
        if(root->data > input->data){
            root->left=insertNode(root->left,input);
        }
        else if(root->data < input->data){
            root->right=insertNode(root->right,input);
        }
        else{
            return root;
        }
        int BF=height(root->right)-height(root->left);
        if(BF>1 && input->data > root->right->data)
        root=leftRotation(root);
        else if(BF<-1 && input->data < root->left->data )
        root=rightRotation(root);
        else if(BF>1 && input->data < root->right->data)
        root=rightLeft(root);
        else if(BF<-1 && input->data > root->left->data)
        root=leftRight(root);
        
        return root;
    }
}

Node* leftRight(Node* root){
    root->left=leftRotation(root->left);
    
    return rightRotation(root);
}

Node* rightLeft(Node* root){
    root->right=rightRotation(root->right);
    
    return leftRotation(root);
}

Node* rightRotation(Node* root){
    Node* newRoot=root->left;
    Node* rightChild=newRoot->right;
    
    newRoot->right=root;
    root->left=rightChild;
    return newRoot;
}

 
Node* leftRotation(Node* root){
    Node* newRoot=root->right;
    Node* leftChild=newRoot->left;
    newRoot->left=root;
    root->right=leftChild;
    return newRoot;
}
int main() {
    // Write C++ code here
    std::cout << "Try programiz.pro";

    return 0;
}
