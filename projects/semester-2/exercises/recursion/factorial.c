#include <stdio.h>

int recursive(int number);

int iterative(int number);

int main() {
    int number = 5;

    printf("Factorial(R) %d! = %d\n", number, recursive(number));

    printf("Factorial(I) %d! = %d\n", number, iterative(number));

    return 0;
}

int recursive(int number) {
    if (number == 0) {
        return 1;
    }

    return number * recursive(number - 1);
}

int iterative(int number) {
    int result = 1;

    for (int i = result; i <= number; i++) {
        result *= i;
    }

    return result;
}