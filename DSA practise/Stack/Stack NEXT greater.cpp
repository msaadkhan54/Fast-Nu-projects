// Online C++ compiler to run C++ program online
#include <iostream>
#include<stack>
using namespace std;
int main() {
    // Write C++ code here
    int arr[5]={6,8,0,1,3};
    stack<int> s;
    int ans[5]={0};
    
    for(int i=4;i>=0;i--){
        if(s.empty()){
            s.push(arr[i]);
            ans[i]=-1;
        }
        else{
            if(s.top()>arr[i]){
                ans[i]=s.top();
            }
            else{
                ans[i]=-1;
            }
            s.push(arr[i]);
        }
    }
    
    for(int i=0;i<5;i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}
