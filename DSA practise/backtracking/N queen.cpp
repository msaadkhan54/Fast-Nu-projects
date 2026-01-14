#include<iostream>
using namespace std;


bool isSafe(char (*arr)[4],int row ,int col,int n){
	for(int i=0;i<n;i++){
		if(arr[i][col]=='q')
		return false;
	}
	for(int i=0;i<n;i++){
		if(arr[row][i]=='q'){
			return false;
		}
	}
	if(row==0){
		return true;
	}
//	for(int i=row;i>=0;i--){
//		for(int j=col;j>=0;j--){
//			if(arr[i][j]=='q'){
//				return false;
//			}
//		}
//	}
//	for(int i=row;i>=0;i--){
//		for(int j=col;j<n;j++){
//			if(arr[i][j]=='q'){
//				return false;
//			}
//		}
//	}
	for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (arr[i][j] == 'q')
            return false;
    }

    // Check right diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (arr[i][j] == 'q')
            return false;
    }
	return true;
}
void queen(char (*arr)[4],int row,int col,int n){
	if(row==n){
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				cout<<arr[i][j]<<" ";
			}
			cout<<endl;
	}
		return;
	}
	for(int i=0;i<n;i++){
		if(isSafe(arr,row,i,n)){
			arr[row][i]='q';
			queen(arr,row+1,col,n);
			arr[row][i]='.';
		}
	}
}

int main(){
	char arr[4][4]={
					{'.','.','.','.'},
					{'.','.','.','.'},
					{'.','.','.','.'},
					{'.','.','.','.'}
				};
	queen(arr,0,0,4);
	
}
