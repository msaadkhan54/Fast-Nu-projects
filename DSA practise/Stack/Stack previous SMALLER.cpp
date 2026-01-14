// Online C++ compiler to run C++ program online
#include <iostream>
#include<stack>
using namespace std;
int main() {
    // Write C++ code here
    int arr[5]={3,1,0,8,6};
    stack<int> s;
    int ans[5]={0};
    
    for(int i=0;i<5;i++){
        while(s.size()>0 && s.top()>=arr[i]){
            s.pop();
        }
        if(s.empty()){
            ans[i]=-1;
        }
        else{
            ans[i]=s.top();
        }
        s.push(arr[i]);
    }
    
    for(int i=0;i<5;i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}
