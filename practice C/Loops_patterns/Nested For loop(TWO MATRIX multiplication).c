#include<stdio.h>
// |1 2|  |5 6|
// |3 4|  |7 8|
int main(){
	int i,j,k;
	int mat1[2][2]={{1,2},{3,4}};
	int mat2[2][2]={{5,6},{7,8}};
	int mat3[2][2]={0};
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			for(k=0;k<2;k++){
				mat3[i][j]+=(mat1[i][k]*mat2[k][j]);
			}
		}
	}
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			printf("%d ",mat3[i][j]);
		}
		printf("\n");
	}
}
