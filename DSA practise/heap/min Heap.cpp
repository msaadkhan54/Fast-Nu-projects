#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class minHeap{
	public:
		int *arr;
		int size;
		int cap;
		minHeap(int size):size(size){
			arr=new int[size];
			cap=0;
		}
		
		void insert(int val){
			if(cap>=size){
				cout<<"Heap Overflow"<<endl;
				return;
			}
			int i=cap;
			cap++;
			arr[i]=val;
			while(i!=0 && arr[(i-1)/2]>arr[i]){
				swap(arr[(i-1)/2],arr[i]);
				i=(i-1)/2;
			}
		}
		
		void deleteNode(){
			if(cap<=0){
				cout<<"Heap underlow"<<endl;
				return;
			}
			arr[0]=arr[cap-1];
			cap--;
			if(cap<=0)return;
			heapify(0);
		}
		
		void heapify(int i){
			int smallest=i;
			int left=2*i+1;
			int right=2*i+2;
			if(left<cap && arr[left]<arr[smallest]){
				smallest=left;
			}
			if(right<cap && arr[right]<arr[smallest]){
				smallest=right;
			}
			if(smallest!=i){
				swap(arr[smallest],arr[i]);
				heapify(smallest);
			}
		}
		
		void print(){
			for(int i=0;i<cap;i++){
				cout<<arr[i]<<" ";
			}
			cout<<endl;
		}
		
		~minHeap(){
			delete[] arr;
			arr=NULL;
		}
		
};

int main(){
	minHeap h1(7);
	h1.insert(10);
	h1.insert(8);
	h1.insert(3);
	h1.insert(5);
	h1.insert(1);
	h1.insert(12);
	h1.print();
}
