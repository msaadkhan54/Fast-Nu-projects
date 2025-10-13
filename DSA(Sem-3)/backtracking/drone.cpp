#include<iostream>
using namespace std;

void drone(char arr[][6],int row,int col,char result[][6]){
	if(row<0 || col<0 || row>=6 || col>=6 || arr[row][col]=='F'){
		return;
	}
	if(arr[row][col]=='H'){
		result[row][col]='H';
		int count=0;
		for(int i=0;i<6;i++){
			for(int j=0;j<6;j++){
				if(result[i][j]=='S'){
					count++;
				}
			}
		}
		if(count<=8){
			cout<<"PAttern: "<<endl;
			for(int i=0;i<6;i++){
				for(int j=0;j<6;j++){
					cout<<result[i][j]<<" ";
				}
				cout<<endl;
			}
			cout<<endl;	
		}
		return;
	}
	result[row][col]=arr[row][col];
	arr[row][col]='F';
	drone(arr,row+1,col,result);
	drone(arr,row-1,col,result);
	drone(arr,row,col+1,result);
	drone(arr,row,col-1,result);
	arr[row][col]=result[row][col];
	result[row][col]='o';
}

int main(){
	char arr[6][6]={{'D','S','S','F','D','F'},
					{'S','S','S','F','S','D'},
					{'S','D','S','S','S','F'},	
					{'F','S','F','S','S','F'},
					{'S','S','S','D','S','F'},
					{'S','F','S','S','S','H'}
						};
	char result[6][6];
	for(int i=0;i<6;i++){
		for(int j=0;j<6;j++){
			result[i][j]='o';
		}
	}
	drone(arr,0,0,result);
}
