#include<iostream>
using namespace std;

bool isSafe(int arr[][9],int row,int col,int n,int digit){
	for(int i=0;i<n;i++){
		if(arr[row][i]==digit){
			return false;
		}
	}
	for(int i=0;i<n;i++){
		if(arr[i][col]==digit){
			return false;
		}
	}
	int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (arr[startRow + i][startCol + j] == digit)
                return false;
        }
    }
    return true;
}

void suduko(int arr[][9],int row,int col,int n){
	if(row==n ){
		for (int i = 0; i < 9; i++) {
        if (i % 3 == 0 && i != 0)
            cout << "---------------------\n";
        for (int j = 0; j < 9; j++) {
            if (j % 3 == 0 && j != 0) cout << "| ";
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
		return ;
	}
	if (col == 9) return suduko(arr, row + 1, 0,n);

    // skip pre-filled cells
    if (arr[row][col] != 0) return suduko(arr, row, col + 1,n);
	
	for(int i=0;i<n;i++){
		if(isSafe(arr,row,col,n,i+1)){
			arr[row][col]=i+1;
			suduko(arr,row,col+1,n);
			arr[row][col]=0;
		}
	}
}

int main(){
	int arr[9][9] = {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };
	
	suduko(arr,0,0,9);
}
