#include<iostream>
#include<queue>
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

Node* getMin(Node* root){
	while(root->left != NULL){
		root = root->left;
	}
	return root;
}

Node* searchNode(Node* root, int data){
	if(root == NULL || root->data == data){
		return root;
	}
	if(data < root->data){
		return searchNode(root->left, data);
	}
	else{
		return searchNode(root->right, data);
	}
}

Node* insert(Node* root, int data){
	if(root == NULL){
		return new Node(data);
	}
	if(data < root->data){
		root->left = insert(root->left, data);
	}
	else{
		root->right = insert(root->right, data);
	}
	return root;
}

Node* deleteNode(Node* root, int data){
	if(root == NULL){
		return root;
	}
	if(data < root->data){
		root->left = deleteNode(root->left, data);
	}
	else if(data > root->data){
		root->right = deleteNode(root->right, data);
	}
	else{
		if(root->left == NULL){
			Node* temp = root->right;
			delete root;
			return temp;
		}
		else if(root->right == NULL){
			Node* temp = root->left;
			delete root;
			return temp;
		}
		else{
			Node* temp = getMin(root->right);
			root->data = temp->data;
			root->right = deleteNode(root->right, temp->data);
		}
	}
	return root;
}

void levelOrderTraversal(Node* root){
	if(root == NULL) return;

	queue<Node*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()){
		Node* curr = q.front();
		q.pop();

		if(curr == NULL){
			cout << endl;
			if(!q.empty()){
				q.push(NULL);
			}
		}
		else{
			cout << curr->data << " ";
			if(curr->left) q.push(curr->left);
			if(curr->right) q.push(curr->right);
		}
	}
}

int main(){
	Node* root = createNode(7);
	root->left = createNode(5);
	root->left->left = createNode(4);
	root->left->right = createNode(6);
	root->right = createNode(9);
	root->right->left = createNode(8);
	root->right->right = createNode(10);

	cout << "Level Order Traversal:" << endl;
	levelOrderTraversal(root);
	
	root=deleteNode(root,5);
	cout << "Level Order Traversal:" << endl;
	levelOrderTraversal(root);

	return 0;
}

