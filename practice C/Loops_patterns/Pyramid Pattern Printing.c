
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
int main() {
    char buffer[100];
    printf("Enter string: ");
    scanf("%s",buffer);
    int lenght=strlen(buffer);
    char *ptr;
    ptr=(char*)malloc(lenght*sizeof(char));
    strcpy(ptr,buffer);
    for(int i=0;i<lenght;i++){
        for(int j=lenght-i;j>=0;j--){
            printf(" ");
        }
        for(int k=0;k<i+1;k++){
            printf("%c ",ptr[k]);
        }
        printf("\n");
    }
    return 0;
}
