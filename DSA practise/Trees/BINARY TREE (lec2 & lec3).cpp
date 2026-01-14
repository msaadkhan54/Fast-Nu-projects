// Online C++ compiler to run C++ program online
#include <iostream>

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
int height(Node* root){
    if(root==NULL)return 0;
    int left=height(root->left);
    int right=height(root->right);
    return left>right?left+1:right+1;
}

int countNodes(Node* root){
    if(root==NULL)return 0;
    int left=countNodes(root->left);
    int right=countNodes(root->right);
    return left+right+1;
}

int sumOfNodes(Node* root){
    if(root==NULL)return 0;
    int left=sumOfNodes(root->left);
    int right=sumOfNodes(root->right);
    return right+left+root->data;
}

bool isIdentical(Node* p,Node* q){
    if(p==NULL || q==NULL)return p==q;
    bool isLeftSame=isIdentical(p->left,q->left);
    bool isRightSame=isIdentical(p->right,q->right);
    return isLeftSame && isRightSame && p->data==q->data;
}

bool isSubTree(Node* root,Node* subTree){
    if(root==NULL || subTree==NULL)return root==subTree;
    if(root->data==subTree->data && isIdentical(root,subTree)){
        return true;
    }
    return isSubTree(root->left,subTree) || isSubTree(root->right,subTree);
    
}
int main() {
    // Write C++ code here
    std::cout << "Try programiz.pro";

    return 0;
}
