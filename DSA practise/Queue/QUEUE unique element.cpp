// Online C++ compiler to run C++ program online
#include <iostream>
#include<queue>
#include<unordered_map>
using namespace std;
int main() {
    // Write C++ code here
    queue<int> q;
    char arr[5]={'l', 'e', 'v', 'e', 'l'};
    unordered_map<char,int> m;
    for(int i=0;i<5;i++){
        m[arr[i]]=0;
    }
    for(int i=0;i<5;i++){
        m[arr[i]]++;
        if(m[arr[i]]==1){
            q.push(i);
        }
        while(q.size()>0 && m[arr[q.front()]]>1){
            q.pop();
        }
    }
    
    if(q.empty()){
        cout<<"No Unique character found"<<endl;
    }
    else{
        cout<<"Unique characters are:";
        while(!q.empty()){
            cout<<arr[q.front()]<<" ";
            q.pop();
        }
    }
    

    return 0;
}
