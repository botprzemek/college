#include <stdio.h>

void square(int* number) {
    *number *= *number;
}

int main() {
    int number = 0;

    printf("Enter number to be squared: ");
    scanf("%d", &number);

    printf("\nOperation: %d^2 = ", number);

    square(&number);
    printf("%d", number);

    return 0;
}
