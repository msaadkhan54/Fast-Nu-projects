#include<iostream>
#include<cstring>

using namespace std;

int main(){
	int count=0;
	char text[]="Hello world";
	int len=strlen(text);
	char upp[len];
	
	cout<<"UPPERCASE: ";
	for(int i=0;i<len;i++){
		if(text[i]>=97 && text[i]<=122){
			upp[i]=text[i]-32;
		}
		else{
			upp[i]=text[i];
		}
	}
	
	for(int i=0;i<len;i++){
		cout<<upp[i];
	}
	
	cout<<endl;
	
	for(int i=0;i<len;i++){
		if(text[i]=='a' || text[i]=='e' || text[i]=='i' || text[i]=='o' || text[i]=='u'){
			count=count+1;
		}
	}
	
	cout<<"VOWEl COUNT: "<<count<<endl;
	cout<<"No Spaces: ";
	
	for(int i=0;i<len;i++){
		if(text[i]==' ')
		continue;
		else{
			cout<<text[i];
		}
	}
}
