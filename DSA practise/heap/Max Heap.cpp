#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Heap{
    public:
        int *arr;
        int size;
        int currSize;
        Heap(int size):size(size){
            arr=new int[size];
            currSize=0;
        }

        void insertHeap(int val){
            if(currSize>=size){
                cout<<"Heap OverFlow"<<endl;
                return;
            }
            int i=currSize;
            currSize++;
            arr[i]=val;

            while(i!=0 && arr[(i-1)/2]<arr[i]){
                swap(arr[(i-1)/2],arr[i]);
                i=(i-1)/2;
            }
        }
        void heapify(int i){
            int largest=i;
            int left=2*i+1;
            int right=2*i+2;
            if(left<currSize  && arr[largest]<arr[left])
            largest=left;
            if(right<currSize  && arr[largest]<arr[right])
            largest=right;
            if(largest!=i){
                swap(arr[largest],arr[i]);
                heapify(largest);
            }
        }
        void deleteNode(){
            if(currSize<1){
                cout<<"Heap Underflow"<<endl;
                return;
            }
            arr[0] = arr[currSize - 1];
			currSize--;
            if(currSize<1){
                return;
            }
           heapify(0);
        }

        

        ~Heap(){
            delete[] arr;
        }
        void print(){
        	for(int i=0;i<currSize;i++){
        		cout<<arr[i]<<" ";
			}
		}
		
		
};





int main(){
    
   Heap h1(7);
   h1.insertHeap(10);
   h1.insertHeap(3);
   h1.insertHeap(9);
   h1.insertHeap(1);
   h1.insertHeap(7);
   h1.deleteNode();
   h1.print();
}
