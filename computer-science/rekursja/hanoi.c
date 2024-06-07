#include <stdio.h>

void hanoi(int dyski, char skad, char dokad, char aux);

int main() {
    int dyski = 3; // Liczba dysków

    // Wywołujemy funkcję
    hanoi(dyski, 'A', 'C', 'B');

    return 0;
}

void hanoi(int dyski, char skad, char dokad, char aux) {
    // Jeśli ilość dysków jest równa zero dokad przenosimy
    if (dyski == 1) {
        printf("Przenieś dysk 1 z %c do %c\n", skad, dokad);
        return;
    }

    hanoi(dyski - 1, skad, aux, dokad);
    printf("Przenieś dysk %d z %c do %c\n", dyski, skad, dokad);

    hanoi(dyski - 1, aux, dokad, skad);
}
