// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
#include<stack>
int largestRectangle(vector<int>&h){
    vector<int> right(h.size(),0);
    vector<int> left(h.size(),0);
    stack<int> s;
    for(i=h.size()-1;i>=0;i--){
        while(h.size()>0 && h[s.top()]>=h[i]){
            s.pop();
        }
        if(s.empty()){
            right[i]=h.size();
        }
        else{
            right[i]=s.top();
        }
        s.push(i);
    }
    
    while(!s.empty()){
        s.pop();
    }
    
    for(int i=0;i<h.size();i++){
        while(h.size() && h[s.top()]>=h[i]){
            s.pop();
        }
        if(s.empty()){
            left[i]=-1;
        }
        else{
            left[i]=s.top();
        }
        s.push(i);
    }
    ans=0;
    for(int i=0;i<h.size();i++){
        int currArea=h[i]*(right[i]-left[i]-1);
        if(currArea>ans){
            ans=currArea;
        }
    }
    return ans;
}

int main() {
    // Write C++ code here
    std::cout << "Try programiz.pro";

    return 0;
}
