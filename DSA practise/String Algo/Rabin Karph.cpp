// Online C++ compiler to run C++ program online
#include <iostream>
#include<cstring>
#include<math.h>
using namespace std;

int hashVal(string str,int base,int n){
    int hash=0;
    for(int i=0;i<n;i++){
        hash+=(str[i]-'a')*pow(base,n-i-1);
    }
    hash%=3;
    return hash;
}

void rabinKarph(string text,string pat){
    int n=pat.length();
    int m=text.length();
    int base=3;
    int hashPat=hashVal(pat,base,n);
    int hashText=hashVal(text.substr(0,n),base,n);
    for(int i=0;i<m-n+1;i++){
        if(hashText==hashPat){
            bool match=true;
            for(int j=0;j<n;j++){
                if(text[i+j]!=pat[j]){
                    match=false;
                    break;
                }
            }
            if(match){
                cout<<"Found at index "<<i<<endl;
            }
        }
        if(i<m-n+1){
            hashText=(hashText-((text[i]-'a')*pow(base,n-1)))*base+(text[i+n]-'a');
            hashText%=3;
        }
    }
}

int main() {
    string text="hello jaanii";
    string pat="nii";
    rabinKarph(text,pat);
    return 0;
}