#include <stdio.h>

// Recursive function to convert decimal to binary
void decimalToBinary(int n) {
    if (n == 0) {
        return;
    }

    decimalToBinary(n / 2); // Recursive call
    printf("%d", n % 2);     // Print remainder (0 or 1)
}

int main() {
    int num;

    printf("Enter a decimal number: ");
    scanf("%d", &num);

    if (num == 0) {
        printf("Binary: 0\n");
    } else {
        printf("Binary: ");
        decimalToBinary(num);
        printf("\n");
    }

    return 0;
}



