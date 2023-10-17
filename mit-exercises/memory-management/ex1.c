#include <stdio.h>

void square(int* number) {
    *number *= *number;
}

int main() {
    int number = 4;

    printf("Normal value: %d\n", number);
    square(&number);
    printf("Squared value: %d", number);

    return 0;
}
