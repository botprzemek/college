#include <stdio.h>

void amaze1(int *amount) {
    for (int i = 0; i < *amount; i++) {
        if (i % 2 == 1) printf("%d, ", i);
    }
}

void amaze2(int *amount) {
    int i = 0;

    while (i < *amount) {
        if (i++ % 2 != 1) printf("%d, ", i);
    }
}

void amaze3(int *amount)  {
    int i = 0;

    do {
        if (i++ % 2 == 0) printf("%d, ", i);
    }
    while (i < *amount);
}

void amaze4(int *amount, int i) {
    if (i == *amount) return;
    if (i % 2 == 1) printf("%d, ", i);
    amaze4(amount, ++i);
}

void amaze5(int *amount) {
    int i = 0;

    amaze:
        if (i == *amount) return;
        if (i % 2 == 1) printf("%d, ", i);

    i++;
    goto amaze;
}

void amaze6(int *amount) {
    for (int i = 0; i < *amount; i++) {
        switch (i % 2) {
            case 1:
                printf("%d, ", i);
                break;
            default:
                break;
        }
    }
}

int main(){
    int amount = 0;

    printf("Enter amount of odd numbers: ");
    scanf("%d", &amount);

    printf("\namaze1: ");
    amaze1(&amount);
    printf("\namaze2: ");
    amaze2(&amount);
    printf("\namaze3: ");
    amaze3(&amount);
    printf("\namaze4: ");
    amaze4(&amount, 0);
    printf("\namaze5: ");
    amaze5(&amount);
    printf("\namaze6: ");
    amaze6(&amount);

    return 0;
}