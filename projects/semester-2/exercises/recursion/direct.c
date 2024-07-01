#include <stdio.h>

void recursion(int number);

int main() {
    int number = 5;

    recursion(number);

    return 0;
}

void recursion(int number) {
    if (number == 0) {
        return;
    }

    printf("Direct! %d\n", number);

    recursion(--number);
}