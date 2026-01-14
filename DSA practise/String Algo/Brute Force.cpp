#include<iostream>
using namespace std;

void BruteForceSearch(string text,string pat){
	int pattLength=pat.length();
	int textLength=text.length();
	for(int i=0;i<(textLength-pattLength+1);i++){
		int j;
		for( j=0;j<pattLength;j++){
			if(text[i+j]==pat[j]){
			}
			else{
				break;
			}
		}
		if(j==pattLength){
			cout<<"Found at index: "<<i<<endl;
		}
	}
}

int main(){
	string text="NOBODY NOTICED NOT";
	string pat="NOT";
	BruteForceSearch(text,pat);
}
