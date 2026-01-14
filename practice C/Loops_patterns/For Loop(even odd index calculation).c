//Q 3.	Using nested loops, produce given output format:	
//a.	Output sequence:10, 13, 26, 29, 58, 61

#include <stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    int input;
    int *num;
    printf("Enter number: ");
    scanf("%d",&input);
    num=&input;
    for(int i=0;i<5;i++){
        if(i==0)
        printf("%d ",*num);
        if(i%2==0){
        *num+=3;    
        printf("%d ",*num);}
        else{
            *num*=2;
            printf("%d ",*num);
        }
    }
}
