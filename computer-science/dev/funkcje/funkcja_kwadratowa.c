#include <stdio.h>
#include <math.h>

float kwadrat_liczby(float liczba);

float delta(float wspolczynnik_a, float wspolczynnik_b, float wspolczynnik_c);

float x0(float wspolczynnik_a, float wspolczynnik_b);

float x1(float wspolczynnik_a, float wspolczynnik_b, float wspolczynnik_c);

float x2(float wspolczynnik_a, float wspolczynnik_b, float wspolczynnik_c);

int main() {
    float a = 1.0;
    float b = -3.0;
    float c = 2.0;

    printf("Funkcja kwadratowa dla a - %f, b - %f c - %f\n", a, b, c);

    float delta_val = delta(a, b, c);

    printf("Delta: %f\n", delta_val);

    if (delta_val > 0) {
        printf("Pierwiastek x1: %f\n", x1(a, b, c));
        printf("Pierwiastek x2: %f\n", x2(a, b, c));
    }
    else if (delta_val == 0) {
        printf("Pierwiastek x0: %f\n", x0(a, b));
    }
    else {
        printf("Brak rzeczywistych pierwiastkow\n");
    }

    return 0;
}

float kwadrat_liczby(float liczba) {
    return liczba * liczba;
}

float delta(float wspolczynnik_a, float wspolczynnik_b, float wspolczynnik_c) {
    return kwadrat_liczby(wspolczynnik_b) - (4 * wspolczynnik_a * wspolczynnik_c);
}

float x0(float wspolczynnik_a, float wspolczynnik_b) {
    return -1 * wspolczynnik_b * 0.5 * wspolczynnik_a;
}

float x1(float wspolczynnik_a, float wspolczynnik_b, float wspolczynnik_c) {
    return (-1 * wspolczynnik_b + sqrt(delta(wspolczynnik_a, wspolczynnik_b, wspolczynnik_c))) * 0.5 * wspolczynnik_a;
}

float x2(float wspolczynnik_a, float wspolczynnik_b, float wspolczynnik_c) {
    return (-1 * wspolczynnik_b - sqrt(delta(wspolczynnik_a, wspolczynnik_b, wspolczynnik_c))) * 0.5 * wspolczynnik_a;
}
