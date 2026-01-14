#include<iostream>
using namespace std;

class Node{
	public:
		string name;
		int id;
		int score;
		int quiz;
		int lectures;
		Node* left;
		Node* right;
		Node(int q,int l,string n,int id):quiz(q),lectures(l),name(n),id(id){
			score=q+l;
			left=right=NULL;
		}
};

Node* NodeSuccessor(Node* root){
	while(root->left!=NULL){
		root=root->left;
	}
	return root;
}

Node* createNode(int q,int l,string n,int i){
	return new Node(q,l,n,i);
}

	Node* insertNode(Node* root,Node* newOne){
		if(root==NULL){
			return newOne;
		}
		if(root->score<newOne->score){
			root->right=insertNode(root->right,newOne);
		}
		else{
			root->left=insertNode(root->left,newOne);
		}
	}
	
	void findStudent(Node* root,string status){
		if(status=="least"){
			if(root->left==NULL){
				cout<<"Name: "<<root->name<<endl;
				cout<<"Id: "<<root->id<<endl;
				cout<<"Quizez: "<<root->quiz<<endl;
				cout<<"Lectures: "<<root->lectures<<endl<<endl;
				return;
			}
			findStudent(root->left,status);
		}
		else if(status=="most"){
			if(root->right==NULL){
				cout<<"Name: "<<root->name<<endl;
				cout<<"Id: "<<root->id<<endl;
				cout<<"Quizez: "<<root->quiz<<endl;
				cout<<"Lectures: "<<root->lectures<<endl<<endl;
				return;
			}
			findStudent(root->right,status);
	}
}
	
	Node* deleteStudent(Node* root,Node* student){
		if(root==NULL){
			return root;
		}
		if(root->score>student->score){
			root->left=deleteStudent(root->left,student);
		}
		else if(root->score<student->score){
			root->right=deleteStudent(root->right,student);
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
				Node* t=NodeSuccessor(root->right);
				root->name=t->name;
				root->id=t->id;
				root->lectures=t->lectures;
				root->quiz=t->lectures;
				root->right=deleteStudent(root->right,t);
				return root;
			}
		}
	}
	
	void leaderBoard(Node* root){
		if(root==NULL) return;
		static int num=0;
		leaderBoard(root->right);
		num++;
		cout<<num<<": | Name: "<<root->name<<" , ID: "<<root->id<<" , Quiz: "<<root->quiz<<" , "<<"Lectures: "<<root->lectures<<endl;
		leaderBoard(root->left);
	}
	
int main(){
	Node* root=createNode(6,6,"Saad",100);
	insertNode(root,new Node(6,3,"Ali",101));
	insertNode(root,new Node(7,9,"Akbar",102));
	insertNode(root,new Node(6,4,"Umar",103));
	insertNode(root,new Node(7,7,"Fahad",104));
	insertNode(root,new Node(6,5,"Safwan",105));
	insertNode(root,new Node(8,10,"Rayyan",106));
	leaderBoard(root);
	cout<<endl;
	string input;
	cout<<"Enter wether to find least or most active student(least/most): ";
	cin>>input;
	findStudent(root,input);
	cout<<endl<<"The Student: "<<endl<<"Name: "<<root->name<<" ID: "<<root->id
				<<endl<<"Removed due to deactivation"<<endl;
	deleteStudent(root,root);
	cout<<endl<<endl;
	leaderBoard(root);
}

