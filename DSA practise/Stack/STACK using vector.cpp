// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;

class Stack{
  vector<int> v;
  public:
    void push(int val){
        v.push_back(val);
    }
    int top(){
        return v.at(v.size()-1);
    }
    void pop(){
        v.pop_back();
    }
    
    bool empty(){
        return v.size()==0;
    }
};

int main() {
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    

    return 0;
}
