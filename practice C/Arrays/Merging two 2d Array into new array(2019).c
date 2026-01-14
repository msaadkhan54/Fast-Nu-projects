#include<stdio.h>
#include<string.h>
//liver=1,kidney=2,lungs=3,cellno=4,cellnumber=5,skin=6,intestine=7,gnames=8,g1=9,g2=10,g3=11,g4=12;
int main(){
	int i,j,k;
	float cellNameData[4][2]={{4.0,5.0},{0.1,1.0},{0.2,2.0},{0.3,3.0}};
	float cellExpData[5][6]={{8.0,3.0,6.0,7.0,1.0,2.0},
	                          {9.0,2.3,1.7,4.3,3.4,5.4},
	                          {10.0,1.5,3.6,8.1,5.5,2.9},
	                          {11.0,4.1,6.6,5.3,3.9,8.1},
	                          {12.0,9.9,2.7,6.2,5.8,3.3}
	                        };
	float mergeData[5][4];
	for(i=1;i<5;i++){
		mergeData[i][0]=cellExpData[i][0];
	}
	for(i=1;i<4;i++)
	{
		for(j=0;j<6;j++){
			if(cellNameData[i][1]==cellExpData[0][j])
			for(k=0;k<5;k++)
			{
				mergeData[k][i]=cellExpData[k][j];
			}
		}
	}
	for(i=0;i<5;i++)
	{
		for(j=0;j<4;j++)
		printf("%.1f | ",mergeData[i][j]);
		printf("\n");
							}                        
}
