#include<iostream>
#include<vector>
using namespace std;

void permu(string str ,int *check,string &ini){
    if(str.length()==ini.length()){
        cout<<str<<endl;
    }
    for(int i=0;i<ini.length();i++){
        if(check[i]==0){
            check[i]=1;
            permu(str+ini[i],check,ini);
            check[i]=0;
        }
    }
}

int main(){
    string str="abc";
    int check[3]={0};
    string temp="";
    permu(temp,check,str);
}
