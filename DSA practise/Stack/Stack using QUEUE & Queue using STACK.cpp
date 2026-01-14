// Online C++ compiler to run C++ program online
#include <iostream>
#include<stack>
#include<queue>
class Stack{
    queue<int> q1;
    queue<int> q2;
    
    void push(int val){
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(val);
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
    }
    
    void pop(){
        q1.pop();
    }
    int top(){
       return q1.front(); 
    }
    bool empty(){
        return q1.empty();
    }
};

class Queue{
    stack<int> s1;
    stack<int> s2;
    public:
    void push(int val){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        
        s1.push(val);
        
        while(!s2.empty()){
            s1.push(s.top());
            s.pop();
        }
    }
    
    void pop(){
        s1.pop();
    }
    
    int front(){
       return s1.top();
    }
    
    bool empty(){
        return s1.empty();
    }
}

int main() {
    

    return 0;
}
