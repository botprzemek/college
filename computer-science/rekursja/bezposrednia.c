#include <stdio.h>

void bezposrednia(int liczba);

int main() {
    int liczba = 5; // Liczba, która zostanie użyta do pętli rekursywnej

    bezposrednia(liczba);

    return 0;
}

void bezposrednia(int liczba) {
    // Kod funkcji, który ma się wykonać
    printf("Bezpośrednio! %d\n", liczba);

    // Po otrzymaniu liczby do 0 funkcja kończy działanie
    if (liczba == 0) {
        return;
    }

    // Wywułuje samą siebie przy zakończeniu, zmniejszając wartość liczby
    bezposrednia(liczba - 1);
}