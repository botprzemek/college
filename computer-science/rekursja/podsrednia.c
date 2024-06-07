#include <stdio.h>

void posredniaA(int liczba);
void posredniaB(int liczba);

int main() {
    // Liczba, która zostanie użyta do pętli rekursywnej
    int liczba = 6;

    posredniaA(liczba);

    return 0;
}

void posredniaA(int liczba) {
    // Po otrzymaniu liczby do 0 funkcja kończy działanie
    if (liczba == 0) {
        return;
    }

    // Kod funkcji, który ma się wykonać
    printf("Pośrednio A! %d\n", liczba);

    // Wywołujemy funkcje nazwajem, dopóki liczba nie dotrze do zera
    posredniaB(--liczba);
}

void posredniaB(int liczba) {
    // Po otrzymaniu liczby do 0 funkcja kończy działanie
    if (liczba == 0) {
        return;
    }

    // Kod funkcji, który ma się wykonać
    printf("Pośrednio B! %d\n", liczba);

    // Wywołujemy funkcje nazwajem, dopóki liczba nie dotrze do zera
    posredniaA(--liczba);
}