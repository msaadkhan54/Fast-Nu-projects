#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
		float start;
		float end;
		Node* left;
		Node* right;
		Node(float st,float e){
			start=st;
			end=e;
			left=NULL;
			right=NULL;
		}
};

class AVL{
	public:
		
		Node* leftRotation(Node* root){
			Node* newRoot=root->right;
			Node* leftChild=newRoot->left;
			newRoot->left=root;
			root->right=leftChild;
			return newRoot;
		}
		
		Node* rightRotation(Node* root){
			Node* newRoot=root->left;
			Node* rightChild=newRoot->right;
			newRoot->right=root;
			root->left=rightChild;
			return newRoot;
		}
		
		Node* leftRight(Node* root){
			root->left=leftRotation(root->left);
			return rightRotation(root);
		}
		
		Node* rightLeft(Node* root){
			root->right=rightRotation(root->right);
			return leftRotation(root);
		}
		int height(Node* root){
			if(root==NULL){
				return 0;
			}
			int left=height(root->left);
			int right=height(root->right);
			return max(left,right)+1;
		}
		
		Node* insertTask(Node* root,float st,float end){
			if(root==NULL){
				return new Node(st,end);
			}
			if( root->start<=st && st<=root->end || root->start<=end && end<=root->end){
				cout<<"time overlapping"<<endl;
				return root;
			}
			else if(st>root->end){
				root->right=insertTask(root->right,st,end);
			}
			else if(end<root->start){
				root->left=insertTask(root->left,st,end);
			}
			
			
			int bf=height(root->right)-height(root->left);
			if(bf>1 && root->right->start < st){
				root=leftRotation(root);
			}
			else if(bf<-1 && root->left->start > end){
				root=rightRotation(root);
			}
			else if(bf>1 && root->right->start > end){
				root=rightLeft(root);
			}
			else if(bf<-1 && root->right->start < st){
				root=leftRight(root);
			}
			return root;
		}
		
    void inorder(Node* root) {
        if (!root) return;
        inorder(root->left);
        cout << "Task: " << formatTime(root->start)
             << " - " << formatTime(root->end) << endl;
        inorder(root->right);
    }

    string formatTime(float time) {
        int hour = int(time);
        int minutes = round((time - hour) * 100);
        stringstream ss;
        ss << setw(2) << setfill('0') << hour << ":"
           << setw(2) << setfill('0') << minutes;
        return ss.str();
    }
};



int main() {
    AVL schedule;
    Node* root = NULL;

    int n;
    cout << "?? Enter number of tasks: ";
    cin >> n;

    cout << "Enter start and end time in hours.minutes format (e.g., 9.30 10.45):\n";
    for (int i = 0; i < n; i++) {
        float st, end;
        cout << "\nTask " << i + 1 << "  Start: ";
        cin >> st;
        cout << "           End: ";
        cin >> end;

        if (st >= end) {
            cout << " Invalid time range (start >= end)\n";
            continue;
        }
        root = schedule.insertTask(root, st, end);
    }
    cout << "\n Final Task Schedule (sorted by start time):\n";
    schedule.inorder(root);
    return 0;
}
