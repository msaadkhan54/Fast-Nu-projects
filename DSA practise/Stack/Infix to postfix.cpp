#include<iostream>
#include<stack>
using namespace std;

int precendence(char c){
	if(c=='^')return 3;
	if(c=='*' || c=='/')return 2;
	if(c=='+' || c=='-')return 1;
	else{
		return -1;
	}
}

void infixToPostfix(string text){
	string gen="";
	stack<char> s;
	for(int i=0;i<text.length();i++){
		if(text[i]>='A' && text[i]<='Z' ||text[i]>='a' && text[i]<='z' || text[i]>='0' && text[i]<='9'){
			gen+=text[i];
		}
		else if(text[i]=='('){
			s.push(text[i]);
		}
		else if(text[i]==')'){
			while(!s.empty() && s.top()!='('){
				gen+=s.top();
				s.pop();
			}
			s.pop();
		}
		else{
			while(!s.empty() && precendence(text[i])<=precendence(s.top())){
				gen+=s.top();
				s.pop();
			}
			s.push(text[i]);
		}
	}
	
	while(!s.empty()){
		gen+=s.top();
		s.pop();
	}
	cout<<gen<<endl;
}

int main(){
	string text="A+B*(C-D)-";
	infixToPostfix(text);
}
