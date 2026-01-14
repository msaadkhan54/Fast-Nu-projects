#include<iostream>
using namespace std;

//void boyerMore(string pattern ,string text){
//	int m=pattern.length();
//	int n=text.length();
//	int i=0;
//	int flag=0;
//	while(i<=(n-m)){
//		int j;
//		int q;
//		if(!flag)
//		j=m+i-1;
//		q=j;
//		int p=m-1;
//		while(p>=0 && text[q]==pattern[p]){
//			q--;
//			p--;
//		}
//		int pos=0;
//		if(p<0){
//			cout<<"Found at index: "<<i<<endl;
//			return;
//		}
//		else{
//			char c=text[j];
//			int k=m-1;
//			flag=0;
//			while(k>=0 && c!=pattern[k]){
//				k--;
//				pos++;
//			}
//			if(k>=0){
//				j+=pos;
//				flag=1;
//				i+=pos;
//			}
//			else{
//				i+=pos;
//			}
//		}
//	}
//}

void boyerMore(string patt,string text){
    int n=patt.length();
    int m=text.length();
    int i=0;
    while(i<m-n+1){
        int j=i+n-1;
        int k=n-1;
        while(k>=0 && patt[k]==text[j]){
            j--;
            k--;
        }
        if(k<0){
            cout<<"Found at index: "<<i<<endl;
            i+=n;
        }
        else{
            int k=n-1;
            int pos=0;
            while(k>=0 && patt[k]!=text[j]){
                k--;
                pos++;
            }
            if(k<0){
                i+=n;
            }
            else{
                i+=pos;
            }
        }
    }
}

int main(){
	string text="Hellonot";
	string pattern="l";
	boyerMore(pattern,text);
}
