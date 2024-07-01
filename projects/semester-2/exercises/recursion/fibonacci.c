#include <stdio.h>

int recursive(int number);

int iterative(int number);

int main() {
    int number = 10;

    for (int i = 0; i < number; i++) {
        printf("Fibonacci number %d = %d\n", i, recursive(i));
    }

    for (int i = 0; i < number; i++) {
        printf("Fibonacci number %d = %d\n", i, iterative(i));
    }

    return 0;
}

int recursive(int number) {
    if (number <= 1) {
        return number;
    }

    return recursive(number - 1) + recursive(number - 2);
}

int iterative(int number) {
    int result = 0;
    int numbers[number];

    number[0] = 0;
    number[1] = 1;

    return result;
}