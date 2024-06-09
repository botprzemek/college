#include <stdio.h>

float w(float punkt_a_1, float punkt_b_1, float punkt_a_2, float punkt_b_2);

float wx(float punkt_c_1, float punkt_b_1, float punkt_c_2, float punkt_b_2);

float wy(float punkt_a_1, float punkt_c_1, float punkt_a_2, float punkt_c_2);

int main() {
    float a1 = 1.0;
    float a2 = 3.0;

    float b1 = 2.0;
    float b2 = 4.0;

    float c1 = 5.0;
    float c2 = 6.0;

    printf("Wyznaczniki dla a1 - %f, a2 - %f, b1 - %f, b2 - %f, c1 - %f, c21 - %f\n", a1, a2, b1, b2, c1, c2);

    printf("Wyznacznik w: %f\n", w(a1, b1, a2, b2));
    printf("Wyznacznik wx: %f\n", wx(c1, b1, c2, b2));
    printf("Wyznacznik wy: %f\n", wy(a1, c1, a2, c2));

    return 0;
}

float w(float punkt_a_1, float punkt_b_1, float punkt_a_2, float punkt_b_2) {
    return (punkt_a_1 * punkt_b_2) - (punkt_b_1 * punkt_a_2);
}

float wx(float punkt_c_1, float punkt_b_1, float punkt_c_2, float punkt_b_2) {
    return (punkt_c_1 * punkt_b_2) - (punkt_b_1 * punkt_c_2);
}

float wy(float punkt_a_1, float punkt_c_1, float punkt_a_2, float punkt_c_2) {
    return (punkt_a_1 * punkt_c_2) - (punkt_c_1 * punkt_a_2);
}
