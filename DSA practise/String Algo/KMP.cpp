// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int* loo(string patt){
    int n=patt.length();
    int* lcs=new int[n];
    lcs[0]=0;int i=0,j=1;
    while(j<n){
        if(patt[i]==patt[j]){
            lcs[j]=i+1;
            i++;j++;
        }
        else{
            if(i!=0){
                i=lcs[i-1];
                continue;
            }
            lcs[j]=0;
            j++;
        }
    }
    return lcs;
}

int main() {
    string t="ABCABDABCABCABD";
    string pat="BCA";
    int*lcs=loo(pat);
    int j=0,i=0;
    while(i<t.length()){
        if(t[i]==pat[j]){
            i++,j++;
        }
        if(j==pat.length()){
            cout<<"Index: "<<(i-j);
            j = lcs[j - 1];
        }
          else if(i < t.length() && t[i] != pat[j]){
            if(j != 0)
                j = lcs[j - 1];
            else
                i++;
        }
    }
    
    delete[] lcs;
    return 0;
}
