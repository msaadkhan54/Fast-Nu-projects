#include<iostream>
using namespace std;

bool rat(int arr[][4],int ans[][4],int row,int col){
	if(row<0 || col<0 || row>=4 || col>=4 || arr[row][col]==0 ){
		return false;
	}
	if(row==3 && col==3){
		ans[row][col]=1;
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				cout<<ans[i][j]<<" ";
			}
			cout<<endl;
		}
		
		cout<<endl;
		return true;
	}
	ans[row][col]=1;
	arr[row][col]=0;
	rat(arr,ans,row+1,col);
	rat(arr,ans,row-1,col);
	rat(arr,ans,row,col-1);
	rat(arr,ans,row,col+1);
	arr[row][col]=1;
	ans[row][col]=0;
	return false;
}

int main(){
	int arr[4][4]={ {1,0,0,0},
					{1,1,0,1},
					{1,1,0,0},
					{0,1,1,1}
				};
	int mat[4][4];
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			mat[i][j]=0;
		}
	}
	rat(arr,mat,0,0);
}
