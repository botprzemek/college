#include <stdio.h>

void toMiles(const int* kilometers, double* result) {
    const double MILE = 0.65;
    *result = MILE * (double) *kilometers;
}

int main() {
    int input;
    double result;

    printf("Przeliczanie odleglosci wyrazonej w kilometrach na mile\n");

    printf("Podaj odleglosc w kilometrach: ");
    scanf("%d", &input);

    toMiles(&input, &result);

    printf("To w milach: %lf", result);

    return 0;
}