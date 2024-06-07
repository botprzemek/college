#include "stdio.h"

int pomiarySredniej(double pomiary[], int iloscPomiarow) {
    int pomiarySredniej = 0;
    double srednia = 0;

    for (int i = 0; i < iloscPomiarow; i++) {
        srednia += pomiary[i];
        printf("%d\n", srednia);
    }

    srednia = srednia / iloscPomiarow;

    for (int i = 0; i < iloscPomiarow; i++) {
        printf("%d\n", srednia);
        printf("%d\n", pomiary[i]);
        if (pomiary[i] == srednia) pomiarySredniej++;
    }

    return pomiarySredniej;
}

int main() {
    double pomiary[] = { 0.2, 0.3, 0.4 };
    printf("Pomiary: %d\n", pomiarySredniej(pomiary, 4));
    return 0;
}
