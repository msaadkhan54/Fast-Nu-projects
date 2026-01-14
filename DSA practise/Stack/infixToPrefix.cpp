#include<iostream>
#include<stack>
#include<string>
using namespace std;

string reverse(string a) {
    int n = a.size();
    for(int i = 0; i < n / 2; i++) {
        char temp = a[i];
        a[i] = a[n - 1 - i];
        a[n - 1 - i] = temp;
    }
    for (int i = 0; i < n; i++) {
        if (a[i] == '(')
            a[i] = ')';
        else if (a[i] == ')')
            a[i] = '(';
    }
    return a;
}
int precendence(char c){
	if(c=='^')return 3;
	if(c=='*' || c=='/')return 2;
	if(c=='+' || c=='-')return 1;
	else{
		return -1;
	}
}

void infixToPrefix(string text){
	
	string revText=reverse(text);
	string gen="";
	stack<char> s;
	
	for(int i=0;i<revText.size();i++){
			if(revText[i]>='A' && revText[i]<='Z' ||revText[i]>='a' && revText[i]<='z' || revText[i]>='0' && revText[i]<='9'){
			gen+=revText[i];
		}
		else if(revText[i]=='('){
			s.push(revText[i]);
		}
		else if(revText[i]==')'){
			while(!s.empty() && s.top()!='('){
				gen+=s.top();
				s.pop();
			}
			s.pop();
		}
		else{
			if(revText[i]=='^'){
				while(!s.empty() && precendence(revText[i])<=precendence(s.top())){
					gen+=s.top();
					s.pop();
				}
			
			}
			else{
				while(!s.empty() && precendence(revText[i])<precendence(s.top())){
					gen+=s.top();
					s.pop();
				}
			}
			s.push(revText[i]);
		}
	}
	while(!s.empty()){
		gen+=s.top();
		s.pop();
	}
	string result=reverse(gen);
	cout<<result;
}

int main(){
	string text="A+B*(C-D)-E";
	infixToPrefix(text);
//	cout<<reverse(text);
}
