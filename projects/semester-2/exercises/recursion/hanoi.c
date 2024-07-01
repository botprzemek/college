#include <stdio.h>

void hanoi(int discs, char from, char to, char temp);

int main() {
    int discs = 3;

    hanoi(discs, 'A', 'B', 'C');

    return 0;
}

void hanoi(int discs, char from, char to, char temp) {
    if (discs == 1) {
        printf("Move disc 1 from %c to %c\n", from, to);
        return;
    }

    hanoi(discs - 1, from, temp, to);

    printf("Move disc %d from %c to %c\n", from, to);

    hanoi(discs - 1, temp, to, from);
}
