#include<stdio.h>
int main(){
	char name[20];
	int count=0,count1=0;
	scanf("%s",name);
	for(int i=0;i<20;i++){
		if(name[i]>='a'&& name[i]<='z'){
				count++;}
		if(name[i]>='A' && name[i]<='Z')
		count1++;
	}
	printf("The small letters are %d and capital letters are %d",count,count1);
}
