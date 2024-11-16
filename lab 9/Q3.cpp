#include<stdio.h>
#include<string.h>
void encryptmessage(char*a){
	int len=strlen(a);
	for(int i=0;i<len;i++)
	{
		if(*(a +i)>='A' && *(a +i)<='Z')
		*(a +i)=*(a +i) +32;
		if(*(a +i)>='a' && *(a +i)<='z')
		*(a +i)=*(a +i) -48;
		if(*(a +i)==' ')
		*(a +i)='0';
	}
	printf("The entered Text is encrypted\n");
}

void decryptmessage(char *a){
	int len=strlen(a);
	for(int i=0;i<len;i++)
	{
		if(*(a +i)>='a' && *(a +i)<='z')
		*(a +i)=*(a +i) -32;
		if(*(a +i)>='1' && *(a +i)<='J')
		*(a +i)=*(a +i) +48;
		if(*(a +i)=='0')
		*(a +i)=' ';
	}
	printf("The entered Text is decrypted\n");
}
int main(){
	char word[100];
	int choice;
	printf("Enter the message that you want to encrypt\n");
	gets(word);
    encryptmessage(word);
	printf("Here is the encrypted text:\n");
	printf("%s\n",word);
	printf("If you want to decrypt than enter '1'\n");
	scanf("%d", &choice);
	if(choice == 1){
		decryptmessage(word);
		printf("Here is the decrypted text:\n");
	    printf("%s\n",word);
		
	}
}
