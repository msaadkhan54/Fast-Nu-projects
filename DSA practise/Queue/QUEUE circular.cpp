// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
class CircularQueue{
    int* arr;
    int currSize;
    int cap;
    int f,r;
    public:
    CircularQueue(int size){
        arr=new int[size];
        cap=size;
        f=0;
        r=-1;
    }
    ~CircularQueue(){
        delete arr;
    }
    void push(int val){
        if(currSize==cap){
            return;
        }
        r=(r+1)%cap;
        arr[r]=val;
        currSize++;
    }
    
    void pop(){
        if(currSize==0){
            return;
        }
        if(f==r){
        	f=0;
        	r=-1;
		}
        f=(f+1)%cap;
        currSize--;
    }
    int front(){
        return arr[f];
    }
    
    bool empty(){
        return currSize==0;
    }
    void print(){
        for(int i=0;i<cap;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main() {
    // Write C++ code here
    CircularQueue cq(3);
    cq.push(1);
    cq.push(2);
    cq.push(3);
    cq.pop();
    cq.push(4);
    cq.print();
    cout<<"front: "<<cq.front();

    return 0;
}
