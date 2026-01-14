#include<iostream>
#include<queue>
using namespace std;

class City{
	public:
		string name;
		int need;
		float distance;
		long int population;
		long int priorityIdx;
		City* left;
		City* right;
		City(string name,int n,float dis,long int pop):need(n),distance(dis),population(pop),name(name){
			left=right=NULL;
			priorityIdx=n+dis+pop;
		}
};

City* findPredecessor(City* root){
	while(root->right!=NULL){
		root=root->right;
	}
	return root;
}

City* insertCity(City* root,City* newOne){
	if(root==NULL){
		return newOne;
	}
	if(root->priorityIdx>newOne->priorityIdx){
		root->left=insertCity(root->left,newOne);
	}
	if(root->priorityIdx<newOne->priorityIdx){
		root->right=insertCity(root->right,newOne);
	}
	return root;
}

City* deleteCity(City* remv,City* root){
	if(root==NULL){
		return NULL;
	}
	if(root->priorityIdx>remv->priorityIdx){
		root->left=deleteCity(remv,root->left);
	}
	else if(root->priorityIdx<remv->priorityIdx){
		root->right=deleteCity(remv,root->right);
	}
	else{
		if(root->left==NULL){
			City* temp=root->right;
			delete root;
			return temp;
		}
		else if(root->right==NULL){
			City* temp=root->left;
			delete root;
			return temp;
		}
		else{
			City* t=findPredecessor(root->left);
			root->name=t->name;
			root->distance=t->distance;
			root->need=t->need;
			root->population=t->population;
			root->priorityIdx=t->priorityIdx;
			root->left=deleteCity(t,root->left);
			return root;
		}
	}
}

City* createCity(string nam,int n,float dis,long int pop){
	return new City(nam,n,dis,pop);
}

City* updateNeed(City* upd,City* root){
	string nm=upd->name;
	root=deleteCity(upd,root);
	float distance;int need;long int pop;
	cout<<"Enter distance,need & population: ";
	cin>>distance>>need>>pop;
	cout<<"The City "<<nm<<" is being updated successfully"<<endl<<endl;
	City* newCity = new City(nm, need, distance, pop);
	root=insertCity(root,newCity);
	return root;
}

void levelOrderTraversal(City* root){
	queue<City*> q1;
	q1.push(root);
	q1.push(NULL);
	while(!q1.empty()){
		City* temp=q1.front();
		q1.pop();
		if(temp!=NULL){
			cout<<temp->name<<" ";
		}
		if(temp==NULL){
			if(!q1.empty()){
				cout<<endl;
				q1.push(NULL);
				continue;
			}
			else{
				break;
			}
		}
		if(temp->left!=NULL){
			q1.push(temp->left);
		}
		if(temp->right!=NULL){
			q1.push(temp->right);
		}
	}
}

int main(){
	City* root=createCity("Karachi",20,456.6,3456543);
	root->right=createCity("Lahore",587,65.6,6456543);
	root->left=createCity("Peshawar",400,45.6,56543);
	root->left->left=createCity("Quetta",57,65.6,6543);
	root->left->right=createCity("Multan",209,455.54,66543);
	cout<<"Level Order Display:"<<endl;
	levelOrderTraversal(root);cout<<endl<<endl;
	root=updateNeed(root->left,root);cout<<endl;
	cout<<"Level Order Display:"<<endl;
	levelOrderTraversal(root);cout<<endl;
	
	cout<<endl<<"The City Lahore need is fulfilled"<<endl;
	root=deleteCity(root->right,root);
	cout<<endl;
	cout<<"Level Order Display:"<<endl;
	levelOrderTraversal(root);cout<<endl;
	
}

