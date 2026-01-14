#include<iostream>
using namespace std;

class LinearHash{
	int *value;
	int* key;
	bool* occupied;
	int size;
	int count;
	public:
		LinearHash(int s):size(s){
			value=new int[size];
			key=new int[size];
			occupied=new bool[size];
			for(int i=0;i<size;i++){
				occupied[i]=false;
				value[i]=0;
			}
			count=0;
		}
		int HashValue(int k){
			return k%size;
		}
		
		void rehash(){
			int old=size;
			int size=23;
			int count=0;
			
			bool* oldocc=occupied;
			int* oldVal=value;
			int* oldkey=key;
			
			occupied=new bool[size];
			value=new int[size];
			key=new int[size];
			
			for(int i=0;i<size;i++){
				occupied[i]=false;
			}
			for(int i=0;i<old;i++){
				if(oldocc[i]){
					insert(oldVal[i],oldKey[i]);
				}
			}
			delete[] oldocc;
			delete[] val;
			delete[] key1;
			
		}
		
		void insert(int val,int k){
			count++;
			int idx=HashValue(k);
			int start=idx;
			double load=count/size;
			if(load>0.7){
				rehash();
			}
			while(occupied[idx]){
				if(key[idx]==k){
					value[idx]=val;
					return;
				}
				idx=(idx+1)%size;
				if(start==idx){
					cout<<"No space "<<endl;
					return;
				}
			}
			occupied[idx]=true;
			value[idx]=val;
			key[idx]=k;
		}
		
		void deleteVal(int k){
			int idx=HashValue(k);
			int start=idx;
			while(occupied[idx]){
				if(key[idx]==k){
					occupied[idx]=false;
					count--;
					idx=(idx+1)%size;
					while(occupied[idx]){
						occupied[idx]=false;
						insert(value[idx],key[idx]);
						idx=(idx+1)%size;
					}
					return;
				}
				idx=(idx+1)%size;
				if(start==idx){
					cout<<"Not Found"<<endl;
					return;
				}
			}
		}
		void print(){
			for(int i=0;i<size;i++){
				cout<<i+1<<":";
				if(value[i]!=0)cout<<value[i];
				cout<<endl;
			}
			cout<<endl;
		}
		~LinearHash(){
			delete[] value;
			delete[] key;
			delete[] occupied;
		}
};

int main(){
	LinearHash l1(11);
	l1.insert(12,1);
	l1.insert(13,12);
	l1.insert(14,23);
	l1.print();
	l1.deleteVal(12);
	l1.print();
	l1.insert(13,12);
	l1.print();
}
