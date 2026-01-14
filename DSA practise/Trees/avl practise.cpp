#include <iostream>
#include <queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int d):data(d){
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

int getBalance(Node* root){
    if(root==NULL) return 0;
    return height(root->left) - height(root->right);
}

Node* successor(Node* root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}

Node* leftRot(Node* root){
    Node* newRoot=root->right;
    Node* leftChild=newRoot->left;
    newRoot->left=root;
    root->right=leftChild;
    return newRoot;
}

Node* rightRot(Node* root){
    Node* newRoot=root->left;
    Node* rightChild=newRoot->right;
    newRoot->right=root;
    root->left=rightChild;
    return newRoot;
}

Node* deleteNode(Node* root, int d){
    if(root==NULL){
        return root;
    }
    else if(root->data > d){
        root->left = deleteNode(root->left, d);
    }
    else if(root->data < d){
        root->right = deleteNode(root->right, d);
    }
    else{
        if(root->right==NULL){
            Node* temp=root->left;
            delete root;
            return temp;
        }
        else if(root->left==NULL){
            Node* temp=root->right;
            delete root;
            return temp;
        }
        else{
            Node* temp=successor(root->right);
            root->data=temp->data;
            root->right=deleteNode(root->right, temp->data);
        }
    }
    
    if(root == NULL) return root;
    
    int BF = getBalance(root);
    
    // Left-Left Case
    if(BF > 1 && getBalance(root->left) >= 0){
        return rightRot(root);
    }
    // Left-Right Case
    if(BF > 1 && getBalance(root->left) < 0){
        root->left = leftRot(root->left);
        return rightRot(root);
    }
    // Right-Right Case
    if(BF < -1 && getBalance(root->right) <= 0){
        return leftRot(root);
    }
    // Right-Left Case
    if(BF < -1 && getBalance(root->right) > 0){
        root->right = rightRot(root->right);
        return leftRot(root);
    }
    
    return root;
}

void levelOrder(Node* root){
    if(root == NULL) return;
    queue<Node*> q1;
    q1.push(root);
    q1.push(NULL);
    while(!q1.empty()){
        Node* temp=q1.front();
        q1.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q1.empty())
                q1.push(NULL);
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left!=NULL)
                q1.push(temp->left);
            if(temp->right!=NULL)
                q1.push(temp->right);
        }
    }
}

void deleteTree(Node* root){
    if(root == NULL) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}


int main() {
    Node* root=new Node(8);
    root->right=new Node(10);
    root->left=new Node(7);
    root->left->left=new Node(6);
     levelOrder(root);
    deleteNode(root,10);
    cout<<endl<<endl;
    levelOrder(root);
    
    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;
    return 0;
}
