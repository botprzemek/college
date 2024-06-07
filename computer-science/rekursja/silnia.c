#include <stdio.h>

int silnia(int liczba);

int main() {
    int liczba = 5; // Liczba, którą chcemy podnieść do silni

    // Wywołujemy funkcję, aby otrzymać wynik z silni
    printf("Silnia z %d = %d!\n", liczba, silnia(liczba));

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