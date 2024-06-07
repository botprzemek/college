#include <stdio.h>

// Funkcja "silnia" jest przykładem funkcji rekursywnej (liniowej)
int silnia(int liczba);

// Implementacja funkcji "silnia" iteracyjnie
int iteracyjnie(int liczba);

int main() {
    // Liczba, którą chcemy podnieść do silni
    int liczba = 5;

    // Wywołujemy rekurencyjną funkcję, aby otrzymać wynik z silni
    printf("Silnia %d! = %d\n", liczba, silnia(liczba));

    // Wywołujemy iteracyjną funkcję, aby otrzymać wynik z silni
    printf("Silnia %d! = %d\n", liczba, iteracyjnie(liczba));

    return 0;
}

int silnia(int liczba) {
    // Silnia z zera to 1
    if (liczba == 0) {
        return 1;
    }

    // Mnożymy liczbę przez silnię, dopóki nie dojdziemy do zera
    return liczba * silnia(liczba - 1);
}

int iteracyjnie(int liczba) {
    // Silnia z zera to 1
    int wynik = 1;

    // Mnożymy iterację przez silnię, dopóki nie dojdziemy do liczby
    for (int i = 1; i <= liczba; i++) {
        wynik = wynik * i;
        printf("Wynik = %d\n", wynik);
    }

    return wynik;
}