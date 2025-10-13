#include<iostream>
using namespace std;

void squirrel(char arr[][5],char ans[][5],int row,int col,int collected){
	if(row<0 || col<0 || row>=5 || col>=5 || arr[row][col]=='T' || arr[row][col]=='O' ){
		return;
	}
	if(arr[row][col]=='F'){
		squirrel(arr,ans,4,2,collected);
		return;
	}
	ans[row][col] = arr[row][col];
    char prev = arr[row][col];
    arr[row][col] = 'O'; 

    if (prev == 'A') collected++;
	
	if(collected==7){
		for(int i=0;i<5;i++){
			for(int j=0;j<5;j++){
				cout<<ans[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		return;
	}
	
	squirrel(arr,ans,row+1,col,collected);
	squirrel(arr,ans,row-1,col,collected);
	squirrel(arr,ans,row,col+1,collected);
	squirrel(arr,ans,row,col-1,collected);
	
	arr[row][col]=prev;
	ans[row][col]='O';
	return;
}

void fox(char arr[][5], char ans[][5], int row, int col, int collected) {
    if (row < 0 || col < 0 || row >= 5 || col >= 5 || arr[row][col] == 'T' || arr[row][col] == 'O' || arr[row][col] == 'A')
        return;

    // Mark path
    ans[row][col] = arr[row][col];
    char prev = arr[row][col];
    arr[row][col] = 'O'; // visited

    if (prev == 'G') collected++;

    if (collected <= 6) {
        cout << "Fox Path (6 gems):\n";
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++)
                cout << ans[i][j] << " ";
            cout << endl;
        }
        cout << endl;
        return;
    }

    fox(arr, ans, row + 1, col, collected);
    fox(arr, ans, row - 1, col, collected);
    fox(arr, ans, row, col + 1, collected);
    fox(arr, ans, row, col - 1, collected);

    arr[row][col] = prev;   // restore
    ans[row][col] = 'O';    // backtrack
}

int main(){
	char arr[5][5]={{'S','A', 'A', 'T' ,'A'},
					{'A' ,'T' ,'A','A' ,'G'},
					{'T' ,'A' ,'T' ,'A' ,'F'},
					{'A' ,'A' ,'A' ,'T' ,'G'},
					{'A' ,'T' ,'G' ,'T' ,'G'},
					};
	char result[5][5]={{'O','O','O','O','O'},
						{'O','O','O','O','O'},
						{'O','O','O','O','O'},
						{'O','O','O','O','O'},
						{'O','O','O','O','O'}
	};
	char result2[5][5]={{'O','O','O','O','O'},
						{'O','O','O','O','O'},
						{'O','O','O','O','O'},
						{'O','O','O','O','O'},
						{'O','O','O','O','O'}
	};
	squirrel(arr,result,0,0,0);
	cout<<endl;
	fox(arr,result2,2,4,0);
}

