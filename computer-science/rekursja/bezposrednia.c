#include <stdio.h>

void bezposrednia(int liczba);

int main() {
    // Liczba, która zostanie użyta do pętli rekursywnej
    int liczba = 5;

    bezposrednia(liczba);

    return 0;
}

void bezposrednia(int liczba) {
    // Po otrzymaniu liczby do 0 funkcja kończy działanie
    if (liczba == 0) {
        return;
    }

    // Kod funkcji, który ma się wykonać
    printf("Bezpośrednio! %d\n", liczba);

    // Wywułuje samą siebie przy zakończeniu, zmniejszając wartość liczby
    bezposrednia(liczba - 1);
}