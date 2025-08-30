#include<iostream>
using namespace std;

int main(){
	int **week=new int*[7];
	for(int i=0;i<7;i++){
		week[i]=new int[3];
	}
	
	cout<<"Enter temprature: "<<endl;
	for(int i=0;i<7;i++){
		cout<<"Day "<<i+1<<": "<<endl;
		for(int j=0;j<3;j++){
			if(j==0)cout<<"morning: ";
			else if(j==1)cout<<"Afternoon: ";
			else if(j==2) cout<<"Noght: ";
			cin>>week[i][j];
		}
	}
	int min=week[0][0],max=week[0][0];
	for(int i=0;i<7;i++){
		for(int j=0;j<3;j++){
			if(week[i][j]<min){
				min=week[i][j];
			}	
			if(week[i][j]>max){
				max=week[i][j];
			}
		}
	}
	cout<<"Hottest: "<<max<<"C"<<endl<<"Coldest: "<<min<<"C";
	for(int i=0;i<7;i++){
		delete[] week[i];
	}
	delete[] week;
}