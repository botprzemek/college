#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 128

float wczytaj_liczbe_f(char komunikat[]);

float wczytaj_liczbe_z_zakresu(float dol, float gora);

int main() {
    return 0;
}

float wczytaj_liczbe_f(char komunikat[]) {
    char bufor_tekstowy[MAX_LEN];
    printf(komunikat);
    fgets(bufor_tekstowy, MAX_LEN, stdin);
    return atof(bufor_tekstowy);
}

float wczytaj_liczbe_z_zakresu(float dol, float gora) {
    if (dol > gora) {
        printf("\nDolna granica jest wieksza od gornej granicy");
        return 0;
    }

    float liczba;

    while (1) {
        liczba = wczytaj_liczbe_f("");
        printf("\nWprowadź liczbę z zakresu %f - %f: ", dol, gora);

        if (liczba >= dol && liczba <= gora) {
            return liczba;
        }

        printf("\nLiczba poza zakresem");
    }
}
