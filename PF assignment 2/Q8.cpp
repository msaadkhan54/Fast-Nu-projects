#include<stdio.h>


int BinaryToDecimal(int num){
    int multiplier=1,each_bin,sum=0;
	while (num > 0) {
        each_bin = num % 10;
        num = num / 10;
        sum = sum + (multiplier * each_bin);
        multiplier *= 2;
    }
    return sum;
}

int DecimalToBinary(int num){
	int binary=0,base=1;
    while (num>0) {
        binary+=(num%2)*base;
        num/=2;
        base*=10;
    }
    return binary;
	}
	
void DecimalToHexadecimal(int num){
	int rem,i=0,temp;
	char hex[25];
	temp=num;
    while (temp!=0) {
    	rem=temp%16;
    	if(rem<10){
    	hex[i]=rem+48;
    	i++;}
    	else{
    	hex[i]=rem+55;
    	i++;}
    	temp/=16;
    }
    printf("The Hexadecimal number is: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hex[j]);
    }
    printf("\n");
}	

void HexadecimalToDecimal(char hexNum[] ){
	int decimal=0,base=1,length=0;
    while (hexNum[length] != '\0') {
        length++;
    }
    int i;
    for (i= length-1; i>=0; i--) {
        if (hexNum[i]>='0' && hexNum[i]<='9') {
            decimal+=(hexNum[i]-48)*base;
        } else if (hexNum[i]>='A' && hexNum[i]<='F') {
            decimal+=(hexNum[i]-55)*base;
        } else {
            printf("Input invalid.\n");
            return;
        }
        base*=16;
    }
    printf("Decimal number: %d\n", decimal);
}

void BINtoHEX(int num){
	int decimal=BinaryToDecimal(num);
	DecimalToHexadecimal(decimal);
}

void HEXtoBIN(char hexNum[]) {
	int decimal=0,base=1,length=0;
    while (hexNum[length]!='\0') {
        length++;
    }
    int i;
    int j;
    for (i=length-1; i>=0; i--){
        if (hexNum[i]>='0' && hexNum[i]<='9') {
            decimal+=(hexNum[i]-48)*base;
        } else if(hexNum[i]>='A' && hexNum[i]<='F') {
            decimal+=(hexNum[i]-55)*base;
        } else{
            printf("Input invalid.\n");
            return;
        }
        base *= 16;
    }
    char binary[60];
    int index=0;

    if (decimal==0) {
        printf("Binary Number: 0\n");
        return;
    }
    while(decimal>0) {
        binary[index++]=(decimal%2)+'0';
        decimal/=2;
    }
    binary[index]='\0';
    for (j=0; j<index/2; j++) {
        char temp=binary[j];
        binary[j]=binary[index-j-1];
        binary[index-j-1] = temp;
    }
    printf("Binary Number: %s\n", binary);
}


int main()
{
	int type,num;
	char hexNum[25];
	printf("Enter the sequence number.\n 1:Binary to Decimal\n 2:Decimal to Binary\n 3:Decimal to Hexadecimal\n 4:Hexadecimal to decimal\n 5:Binaey to Hexadecimal\n 6:Hexadecimal to Binary\n 7: Exit\n");
	scanf("%d", &type);
	switch(type){
		case 1:
			printf("Enter the Binary number\n");
			scanf("%d", &num);
			printf("The decimal number is %d", BinaryToDecimal(num));
			break;
		case 2:
		    printf("Enter the Decimal number\n");
			scanf("%d", &num);
			printf("The Binary number is : %d", DecimalToBinary(num));
			break;
		case 3:
			printf("Enter the Decimal Number.\n");
			scanf("%d", &num);
			DecimalToHexadecimal(num);
			break;
		case 4:
		    printf("Enter Hexadecimal number.\n");
		    scanf("%s",hexNum);
            HexadecimalToDecimal(hexNum);
		    break;
		case 5:
            printf("Enter a binary number: ");
            scanf("%d",&num);
            BINtoHEX(num);
            break;
        case 6:
            printf("Enter a hexadecimal number: ");
            scanf("%s",hexNum);
            HEXtoBIN(hexNum);
            break;
        case 7:
            printf("Exiting the program.");
            return 0;
        default:
            printf("Input invalid. Please try again :(");
        }
        return 0;
    }

