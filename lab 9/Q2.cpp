#include<stdio.h>
#include<string.h>
int palindrome(char arr[], int column){
	int flag=0,i;
	int lenght=strlen(&arr[0]);
	for(i=0;i<lenght/2;i++){
		if(arr[i]==arr[lenght-i-1])
		flag=1;
		else{
			flag=0;
			break;
		}
	}
	return flag;
}
int main(){
	char word[5][20];
	printf("Enter 5 Words:\n");
	for(int i=0;i<5;i++){
		scanf("%s", &word[i]);
	}
	
	for(int i=0;i<5;i++){
		int result=palindrome(word[i],20);
		if(result==1)
		printf("The '%s' is palindrome\n",word[i]);
		else
		printf("The '%s' is not a palindrome\n",word[i]);
	}
}
