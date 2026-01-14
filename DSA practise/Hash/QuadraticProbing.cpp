#include<iostream>
using namespace std;

class Hash{
    public:
        int* key1;
        bool* occupied;
        int* value1;
        int size;
        Hash(){
            size=11;
            key1=new int[size];
            occupied=new bool[size];
            value1=new int[size];
            for(int i=0;i<size;i++){
                occupied[i]=false;
            }
        }

        int HashValue(int key){
            return key%size;
        }

        void insert(int key,int value){
            int idx=HashValue(key);
            int j=0;
            while(occupied[idx]){
                j++;
                if(key1[idx]==key){
                    value1[idx]=value;
                    cout<<"Overwritten"<<endl;
                    return;
                }
                idx=(idx+(j*j))%size;
            }
            occupied[idx]=true;
            value1[idx]=value;
            key1[idx]=key;
        }

        void remove(int key){
            int idx=HashValue(key);
            int j=0;
            while(occupied[idx]){
                j++;
                if(key1[idx]==key){
                    occupied[idx]=false;

                    return;
                }
                idx=(idx+(j*j))%size;
            }

        }

        void search(int key){
            int idx=HashValue(key);
            int j=0;
            while(occupied[idx]){
                j++;
                if(key1[idx]==key){
                    cout<<"Found- Value:"<<value1[idx]<<endl;
                    return;
                }
                idx=(idx+(j*j))%size;
            }
        }
        void print(){
            for(int i=0;i<size;i++){
                cout<<i<<":";
                if(occupied[i])cout<<value1[i];
                cout<<endl;
            }
        }
        ~Hash(){
            delete[] key1;
            delete[] value1;
            delete[] occupied;
        }
};

int main(){
    Hash h1;
    h1.insert(3,1);
    h1.insert(36,2);
    h1.insert(47,3);
    h1.print();
}