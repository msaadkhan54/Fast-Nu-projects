#include<iostream>
#include<bits/stdc++.h>
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

Node* createNode(int val){
	return new Node(val);                              
}

int numNodes(Node* root){
	if(root==NULL)return 0;
	int left=numNodes(root->left);
	int right=numNodes(root->right);
	return (1+left+right);
}

void minHeap(Node* root,int* arr){
	static int i=0;
	if(root==NULL)
	return;
	minHeap(root->left,arr);
	arr[i]=root->data;i++;
	minHeap(root->right,arr);
}

int main(){
	Node* root = createNode(5);
	root->left = createNode(3);
	root->right = createNode(6);
	root->left->left = createNode(2);
	root->left->right = createNode(4);
	
	int size=numNodes(root);
	int *arr=new int[size];
	minHeap(root,arr);
	cout<<"MIN HEAP array Representation:"<<endl;
	for(int i=0;i<size;i++){
		cout<<arr[i]<<" ";
	}
	delete[] arr;
	delete root ;
	delete root->left ;
	delete root->right;
	delete root->left->left; 
	delete root->left->right;
}


              
