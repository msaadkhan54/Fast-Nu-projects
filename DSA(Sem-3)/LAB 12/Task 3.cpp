#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* left;
		Node* right;
		
		Node(int d){
			data = d;
			left = right = NULL;
		}
};

Node* createNode(int d){
	return new Node(d);
}

void findingKeysInRange(Node* root,int n1,int n2){
	if(root==NULL){
		return;                                      
	}
	bool found=false;
	if(root->data>=n1 && root->data<=n2){
		found=true;
		cout<<root->data<<" ";
		if(n1<root->data)
		findingKeysInRange(root->left,n1,n2);
		if(root->data<n2)
		findingKeysInRange(root->right,n1,n2);
	}
	if(!found){
		if(root->data<n1){
		findingKeysInRange(root->right,n1,n2);
		}
		if(root->data>n1){
			findingKeysInRange(root->left,n1,n2);
		}
	}
}

int main(){
	Node* root1 = createNode(6);
	root1->left = createNode(3);
	root1->left->left = createNode(2);
	root1->left->right = createNode(5);
	root1->right = createNode(10);
	root1->right->left = createNode(8);
	root1->right->left->left=createNode(7);
	root1->right->left->right=createNode(9);
	root1->right->right = createNode(13);
	
	findingKeysInRange(root1,3,12);
}
