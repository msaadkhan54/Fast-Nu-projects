#include <stdio.h>

int main() {
    int num, count = 0;
    printf("Enter a number: ");
    scanf("%d", &num);
    int temp = num;
    while (temp > 0) {
        if (temp & 1) {
            count++;
        }
        temp = temp >> 1;
    }
    printf("The number of 1s in the binary representation of %d is: %d\n", num, count);

    return 0;
}

