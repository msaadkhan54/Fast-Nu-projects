// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
#include<dequeue>
using namespace std;
 vector<int> window(vector<int>& v,int k){
    vector<int> ans;
    int n=v.size();
    dequeue<int> q;
    for(i=0;i<k;i++){
        while(q.size()>0 && arr[q.front()]<=arr[i]){
            q.pop_back();
        }
        q.push_back(i);
    }
    for(i=k;i<n;i++){
        ans.push(arr[q.front()]);
        while(q.size()>0 && q.front()<=i-k){
            q.pop_front();
        }
        while(q.size()>0 && arr[q.front()]<=arr[i]){
            q.pop_back();
        }
        q.push_back(i);
    }
    ans.push(arr[q.front()]);
    return ans;
}
int main() {
    // Write C++ code here
    std::cout << "Try programiz.pro";

    return 0;
}
