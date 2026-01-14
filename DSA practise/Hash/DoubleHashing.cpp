#include<iostream>
using namespace std;

class DoubleHashing{
public:
    int* key1;
    int* value1;
    bool* occupied;
    int size;
    int count;
    DoubleHashing(){
        count=0;
        size=11;
        key1=new int[size];
        value1=new int[size];
        occupied=new bool[size];
        for(int i=0;i<size;i++){
            occupied[i]=false;
        }
    }

    int Hash1(int key){
        return key%size;
    }

    int Hash2(int key){
        return 7-(key%7);
    }

    void resizing(){
        int oldSize=size;
        size=23;
        count=0;
        int* oldKey=key1;
        int* oldValue=value1;
        bool* oldOcc=occupied;
        key1=new int[size];
        value1=new int[size];
        occupied=new bool[size];
        for(int i=0;i<size;i++){
            occupied[i]=false;
        }
        for(int i=0;i<oldSize;i++){
            if(oldOcc[i]){
                insert(oldKey[i],oldValue[i]);
            }
        }
        delete[] oldKey;
        delete[] oldValue;
        delete[] oldOcc;
    }

    void insert(int key,int value){
        double loadFactor=(count+1)/(double)size;
        if(loadFactor>0.7){
            resizing();
        }
        int idx=Hash1(key);
        int next=idx;
        int j=0;
        while(occupied[idx]){
            j++;
            if(key1[idx]==key){
                value1[idx]=value;
                cout<<"Over Written"<<endl;
                return;
            }
            idx=(Hash1(key)+ j*Hash2(key))%11;
        }
        value1[idx]=value;
        key1[idx]=key;
        occupied[idx]=true;
        count++;
    }

    void remove(int key){
        int idx=Hash1(key);
        int j=0;
        while(occupied[idx]){
            j++;
            if(key1[idx]==key){
                occupied[idx]=false;
                cout<<"Deleted"<<endl;
                return;
            }
            idx=(Hash1(key)+j*Hash2(key))%11;
        }
        cout<<"Not Found"<<endl;
    }

    void search(int key){
        int idx=Hash1(key);
        int j=0;
        while(occupied[idx]){
            j++;
            if(key1[idx]==key){
                occupied[idx]=true;
                cout<<"Found"<<endl;
                return;
            }
            idx=(Hash1(key)+j*Hash2(key))%11;
        }
        cout<<"Not Found"<<endl;
    }

    void print(){
        for(int i=0;i<size;i++){
            cout<<i<<":";
            if(occupied[i])cout<<value1[i];
            cout<<endl;
        }
    }

    ~DoubleHashing(){
        delete[] key1;
        delete[] value1;
        delete[] occupied;
    };

};

int main(){
    DoubleHashing h1;
    h1.insert(34,23);
    h1.insert(3,21);
    h1.insert(56,3);
    h1.insert(43,6);
    h1.insert(2,7);
    h1.insert(22,8);
    h1.insert(67,9);
    h1.insert(11,1);
    h1.print();
}
