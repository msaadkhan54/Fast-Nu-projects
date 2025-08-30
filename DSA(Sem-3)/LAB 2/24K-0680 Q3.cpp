#include<iostream>
using namespace std;
int main(){
	int patient;
	cout<<"Enter number of patients: ";
	cin>>patient;
	string **arr=new string*[patient];
	int medicine[patient];
	
	for(int i=0;i<patient;i++){
		cout<<"Enter number of medicine of patient "<<i+1<<": ";
		cin>>medicine[i];
		arr[i]=new string[medicine[i]];
	}
	cout<<"Enter prescription: "<<endl;
	for(int i=0;i<patient;i++){
		
		string text;
		cout<<"For PATIENT "<<i+1<<": "<<endl;
		
		for(int j=0;j<medicine[i];j++){
			
			cout<<"Enter prescription of medicine "<<j+1<<": ";
			cin>>text;
			
			arr[i][j]=text;
		}
	}
	
	for(int i=0;i<patient;i++){
		cout<<"Patient "<<i+1<<": "<<endl;
		for(int j=0;j<medicine[i];j++){
			cout<<"       Medicine "<<j+1<<": "<<arr[i][j]<<endl;
		}
	}
	
	for(int i=0;i<patient;i++){
		delete[] arr[i];
	}
	
	delete[] arr;  
}