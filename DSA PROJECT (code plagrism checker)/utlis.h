#ifndef UTLIS_H
#define UTLIS_H

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

string readFile(string filepath){
	ifstream input;
	input.open(filepath.c_str());
	string content="",line;
	if(!input.is_open()){
		cout<<"Error.File not opening"<<endl;
		return "error";
	}
	while(!input.eof()){
		getline(input,line);
		content+=line+"\n";
	}
	input.close();
	return content;
}

#endif