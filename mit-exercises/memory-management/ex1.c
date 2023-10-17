#include <stdio.h>

void square(int* number) {
    *number *= *number;
}

int main() {
    int number = 4;

    printf("Operation: %d^2 = ", number);
    square(&number);
    printf("%d", number);

    return 0;
}
