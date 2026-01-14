// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
#include<stack>
using namespace std;

int main() {
    vector<int> price={100,80,60,70,60,75,85};
    vector<int> ans(price.size(),0);
    stack<int> s;
    
    for(int i=0;i<price.size();i++){
        if(s.empty()){
            s.push(i);
            ans[i]=i+1;
        }
        else{
            while(price[s.top()]<=price[i]){
                s.pop();
            }
            ans[i]=i-s.top();
        }
        s.push(i);
    }
    
    for(int i=0;i<price.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
