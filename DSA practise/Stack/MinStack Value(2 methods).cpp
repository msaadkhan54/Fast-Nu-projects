// Online C++ compiler to run C++ program online
#include <iostream>
#include<stack>
using namespace std;

class MinStack{
    public:
    int min;
    stack<pair<int,int>> s;
    MinStack(){
        min=0;
    }
    void push(int val){
        if(s.empty()){
            s.push({val,val});
            min=val;
        }
        else{
            if(val<s.top().second){
                min=val;
            }
            s.push({val,min});
        }
    }
    
    void pop(){
        s.pop();
    }
    int getMin(){
        return s.top().second;
    }
    int top(){
        return s.top().first;
    }
};

class MinStack2{
  public:
    int minValue;
    int temp;
    stack<long long int> s;
    void push(int val){
        if(s.empty()){
            s.push(val);
            minValue=val;
        }
        else{
            if(val<minValue){
                s.push((long long)2*val-minValue);
                minValue=val;
            }
            else{
                s.push(val);
            }
        }
    }
    void pop(){
        if(s.top()<minValue){
            minValue=minValue*2-s.top();
            s.pop();
        }
        else{
            s.pop();
        }
    }
    int top(){
        if(s.top()<minValue){
            return minValue;
        }
       return s.top(); 
    }
    int getMin(){
        return minValue;
    }
};
int main() {
    // Write C++ code here
    // MinStack st;
    // st.push(-2);
    // st.push(0);
    // st.push(-3);
    // cout<<st.getMin()<<"min"<<endl;
    // st.pop();
    // cout<<"top: "<<st.top()<<endl;
    // cout<<st.getMin()<<"min"<<endl;
    
    MinStack2 st;
    st.push(-2);
    st.push(0);
    st.push(-3);
    cout<<st.getMin()<<"min"<<endl;
    st.pop();
    cout<<"top: "<<st.top()<<endl;
    cout<<st.getMin()<<"min"<<endl;

    return 0;
}
