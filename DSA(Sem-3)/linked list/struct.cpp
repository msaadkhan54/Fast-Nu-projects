#include<iostream>
using namespace std;

struct Team{
	string name;
	int score;
	
};

int binarySearch(Team *arr,int n,int target){
	int left=0;
	int right=n-1;
	while(left<=right){
		int mid=left+(right-left)/2;
		if(arr[mid].score==target){
			return mid;
		}
		else if(arr[mid].score>target){
			left=mid+1;
		}
		else if(arr[mid].score<target){
			right=mid-1;
		}
	}
	return -1;
}

void selectionSort(Team *arr,int n){
	for(int i=0;i<n;i++){
		int max=i;
		for(int j=i+1;j<n;j++){
			if(arr[j].score>arr[max].score){
				max=j;
			}
			if(arr[j].score==arr[max].score){
				int text1=arr[j].name.length();
				int text2=arr[max].name.length();
				if(text1>text2){
					max=j;
				}
			
			}
		}
		string text=arr[i].name;
		int num=arr[i].score;
		arr[i].name=arr[max].name;
		arr[i].score=arr[max].score;
		arr[max].score=num;
		arr[max].name=text;
	}
}



int main(){
	Team team[6]={{"Italy", 28}, {"Brazil", 34}, {"Argentina", 30}, {"Germany", 28}, {"Spain", 27}, {"France", 31}};
	selectionSort(team,6);
	for(int i=0;i<6;i++){
		cout<<team[i].score<<endl;
	}
	cout<<"The score 34 is at index: "<<binarySearch(team,6,34);
}
