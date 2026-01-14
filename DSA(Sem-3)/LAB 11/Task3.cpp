#include<iostream>
using namespace std;

class Hash{
    public:
    int* key1;
    int* value1;
    bool* occupied;
    int size;
    int count;
    Hash(){
        size=11;
        key1=new int[size];
        value1=new int[size];
        occupied=new bool[size];
        count=0;
        for(int i=0;i<size;i++){
            occupied[i]=false;
        }
    }
    int HashValue(int key){
        return key%size;
    }

    void resizeTable(){
        int oldSize=size;
        size=23;
        int* oldKey=key1;
        bool*oldOcc=occupied;
        int* oldVal=value1;

        key1=new int[size];
        value1=new int[size];
        occupied=new bool[size];
        for(int i=0;i<size;i++){
            occupied[i]=false;
        }
        count=0;
        for(int i=0;i<oldSize;i++){
            if(oldOcc[i]){
                insert(oldKey[i],oldVal[i]);
            }
        }
        delete[] oldOcc;
        delete[] oldVal;
        delete[] oldKey;

    }

    void insert(int key,int value){
        double loadFactor = (count+1) / (double)size;
        if(loadFactor > 0.7){
            resizeTable();
        }
        int idx=HashValue(key);
        int startIdx=idx;
        while(occupied[idx]){
            if(key1[idx]==key){
                value1[idx]=value;
                cout<<"Overwritten has done"<<endl;
            }
            idx=(idx+1)%size;
            if(startIdx==idx){
                cout<<"Hash table is full"<<endl;
                return;
            }
        }
        occupied[idx]=true;
        key1[idx]=key;
        value1[idx]=value;
        count++;
       
    }


    void remove(int key){
        int idx=HashValue(key);
        int startIdx=idx;
        while(occupied[idx]){
            if(key1[idx]==key){
                occupied[idx]=false;
                idx = (idx + 1) % size;
                while (occupied[idx]) {
                int k = key1[idx];
                int v = value1[idx];

                occupied[idx] = false;  
                insert(k, v);            

                idx = (idx + 1) % size;
            }
                return;
            }
            idx=(idx+1)%size;
            if(startIdx==idx){
                cout<<"Not Found"<<endl;
                return;
            }
        }
    }

    void print() {
        for(int i = 0; i < size; i++) {
            cout << i << ": ";
            if(occupied[i]) cout << value1[i];
            cout << endl;
        }
    }
    ~Hash(){
        delete[] occupied;
        delete[] key1;
        delete[] value1;
    }
};

int main(){
    Hash h1;
    h1.insert(10,1);
    h1.insert(25,2);
    h1.insert(35,3);
    h1.insert(45,4);
    h1.insert(55,5);
    h1.insert(65,6);
    h1.insert(75,7);
    h1.insert(85,8);
    cout << "\nFinal Table:\n";
    h1.print();
}
