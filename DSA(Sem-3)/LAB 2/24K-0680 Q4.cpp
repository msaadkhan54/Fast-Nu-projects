#include<iostream>
using namespace std;

int main(){
	int mat1[3][3];
	int mat2[3][3];
	int mat3[3][3];
	
	cout<<"Enter for Matrix 1: "<<endl;
	for(int i=0;i<3;i++){
		cout<<"Row "<<i+1<<": "<<endl;
		for(int j=0;j<3;j++){
			cout<<"Column "<<j+1<<": ";
			cin>>mat1[i][j];
		}
	}
	cout<<"Enter for Matrix 2: "<<endl;
	for(int i=0;i<3;i++){
		cout<<"Row "<<i+1<<": "<<endl;
		for(int j=0;j<3;j++){
			cout<<"Column "<<j+1<<": ";
			cin>>mat2[i][j];
		}
	}
	cout<<"MATRIX 1:"<<endl;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout<<mat1[i][j];
			if(j!=2){
				cout<<",";
			}
		}
		cout<<endl;
	}
	cout<<endl<<"MATRIX 2:"<<endl;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout<<mat2[i][j];
			if(j!=2){
				cout<<",";
			}
		}
		cout<<endl;
	}
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			mat3[i][j]=mat1[i][j]+mat2[i][j];
		}
	}
	cout<<endl<<"MATRIX 3 (Final Sum):"<<endl;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout<<mat3[i][j];
			if(j!=2){
				cout<<",";
			}
		}
		cout<<endl;
	}
}
