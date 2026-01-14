#ifndef TOKENIZER_H
#define TOKENIZER_H


#include<iostream>
#include<vector>
using namespace std;
vector<string> tokenize(string code) {
    vector<string> tokens;
    string token = "";

    for (int i = 0; i < code.size(); i++) {
        char c = code[i];
        if (isspace(c)) {
            if (!token.empty()) {
                tokens.push_back(token);
                token.clear();
            }
        }
        else if (ispunct(c) && c != '_' && c != '"') { 
            if (!token.empty()) {
                tokens.push_back(token);
                token.clear();
            }
            string temp(1, c);
            tokens.push_back(temp);
        }
        else {
            token += c;
        }
    }
    if (!token.empty()) tokens.push_back(token);
    return tokens;
}


string removeSpace(string code){
	string extraSpaceDel="";
	bool isspace=false;
	for(int i=0;i<code.length();i++){
		if(code[i]=='\t'){
				extraSpaceDel+=" ";
		}
		else if(code[i]==' '){
			if(!isspace){
				extraSpaceDel+=code[i];
				isspace=true;
			}
		}
		else{
			extraSpaceDel+=code[i];
			isspace=false;
		}
	}
	return extraSpaceDel;
}

string removeComments(string code){
	string commentsFreeCode="";
	for(int i=0;i<code.length();i++){
		if(code[i]=='/' && i+1<code.length() && code[i+1]=='/'){
			i+=2;
			while(code[i]!='\n'){
				i++;
			}
		}
		else if(code[i]=='/' && i+1<code.length() && code[i+1]=='*'){
			i+=2;
			while(code[i]!='*' && i+1<code.length() && code[i+1]=='/'){
				i++;
			}
			i++;
		}
		else {
            commentsFreeCode += code[i];
        }
	}
	return commentsFreeCode;
}


string cleaning(string code){
	code=removeComments(code);
    code=removeSpace(code);
    return code;
}

#endif