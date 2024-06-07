#include <stdio.h>

void hanoi(int dyski, char skad, char dokad, char tymczasowy);

int main() {
    // Liczba dysków
    int dyski = 3;

    hanoi(dyski, 'A', 'C', 'B');

    return 0;
}

void hanoi(int dyski, char skad, char dokad, char tymczasowy) {
    // Jeśli ilość dysków jest równa zero dokąd przenosimy
    if (dyski == 1) {
        printf("Przenieś dysk 1 z %c do %c\n", skad, dokad);
        return;
    }

    hanoi(dyski - 1, skad, tymczasowy, dokad);
    printf("Przenieś dysk %d z %c do %c\n", dyski, skad, dokad);

    hanoi(dyski - 1, tymczasowy, dokad, skad);
}
