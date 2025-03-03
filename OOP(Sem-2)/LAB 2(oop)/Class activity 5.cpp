#include<iostream>
using namespace std;

int main(){
	int rows=3,cols=3,sum=0;
	int **matrix=new int*[rows];
	for(int i=0;i<cols;i++){
		matrix[i]=new int[cols];
	}
	
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			cout<<"Enter Value at Row "<<i+1<<" column "<<j+1<<" :";
			cin>>matrix[i][j];
		}
	}
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			sum+=matrix[i][j];
		}
	}
	cout<< "The sum is "<<sum<<endl;
	for(int i=0;i<rows;i++){
		delete[] matrix[i];
	}
	
	delete matrix;
	
}