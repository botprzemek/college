#include <stdio.h>

int factorialIteration(int number) {
    if (number < 1) return 0;
    int result = 1;
    for (int i = number; i > 1; i--) result *= i;
    return result;
}

int factorialRecursion(int number, int result) {
    if (number <= 0) return result;
    result *= number--;
    return factorialRecursion(number, result);
}

int powerIteration(int number, int to) {
    int result = number;
    for (int i = to; i > 1; i--) result *= number;
    return result;
}

int powerRecursion(int number, int to, int result) {
    if (to-- <= 0) return result;
    result *= number;
    return powerRecursion(number, to, result);
}


int main() {
    printf("Iteration: %d\n", factorialIteration(4));
    printf("Recursion: %d\n", factorialRecursion(4, 1));

    printf("Iteration: %d\n", powerIteration(2, 4));
    printf("Recursion: %d\n", powerRecursion(2, 4, 1));

    return 0;
}