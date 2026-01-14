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
bool sameItems(Node* root,Node* subRoot){
	if(root==NULL){
		return false;
	}
	if(subRoot==NULL)return true;
	bool found=false;
	if(root->data==subRoot->data){
		found=true;
		return found && sameItems(root,subRoot->left) && sameItems(root,subRoot->right);
	}
	if(root->data>subRoot->data){
		return sameItems(root->left,subRoot);
	}
	else if(root->data<subRoot->data){
		return sameItems(root->right,subRoot);
	}
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
	Node* root1 = createNode(6);
	root1->left = createNode(3);
	root1->left->left = createNode(4);
	root1->left->right = createNode(5);
	root1->right = createNode(10);
	root1->right->left = createNode(8);
	root1->right->left->left=createNode(7);
	root1->right->left->right=createNode(9);
	root1->right->right = createNode(13);
	
	Node* root2=createNode(10);
	root2->left = createNode(8);
	root2->left->right= createNode(9);
	root2->right = createNode(13);
	
	cout<<"BST 1:"<<endl;
	levelOrderTraversal(root1);
	
	cout<<endl<<"BST 2:"<<endl;
	levelOrderTraversal(root2);
	
	if(sameItems(root1,root2))
	cout<<"two BSTs contain the same set of elements ";
	else{
		cout<<"two BSTs doesnot contain the same set of elements";
	}
	
}
