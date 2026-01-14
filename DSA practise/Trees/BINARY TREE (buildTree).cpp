#include <iostream>
#include <vector>
#include<queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Global static variable
int idx = -1;

// Correct buildTree function
Node* buildTree(vector<int>& pre) {
    idx++;
    if (pre[idx] == -1) {
        return NULL;
    }
    Node* root = new Node(pre[idx]);
    root->left = buildTree(pre);
    root->right = buildTree(pre);
    return root;
}

// Traversal functions
void preOrderTraversal(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void inOrderTraversal(Node* root) {
    if (root == NULL) return;
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

void postOrderTraversal(Node* root){
    if(root==NULL){
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data<<" ";
}

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(q.size()>0){
        Node* curr=q.front();
        cout<<curr.data<<" ";
        if(curr==NULL){
            if(!q.empty()){
                cout<<endl;
                q.push(NULL);
                continue;
            }
            else{
                break;
            }
        }
        if(curr->left!=NULL){
            q.push(curr->left);
        }
        if(curr->right!=NULL){
            q.push(curr->right);
        }
    }
}

int main() {
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node* root = buildTree(preorder);

    cout << "Preorder: ";
    preOrderTraversal(root);
    cout << "\nInorder: ";
    inOrderTraversal(root);
    cout << "\nPostorder: ";
    postOrderTraversal(root);
    cout << "\nLevelorder: ";
    levelOrderTraversal(root);
    return 0;
}

