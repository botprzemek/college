#include <stdio.h>

void indirectA(int number);

void indirectB(int number);

int main() {
    int number = 6;

    indirectA(number);

    return 0;
}

void indirectA(int number) {
    if (number == 0) {
        return;
    }

    printf("Indirect A! %d\n", number);
    indirectB(--number);
}

void indirectB(int number) {
    if (number == 0) {
        return;
    }

    printf("Indirect B! %d\n", number);
    indirectA(--number);
}