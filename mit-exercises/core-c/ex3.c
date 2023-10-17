#include <stdio.h>

void amaze1() {
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 1) printf("%d, ", i);
    }
}

void amaze2() {
    int i = 0;

    while (i < 10) {
        if (i++ % 2 != 1) printf("%d, ", i);
    }
}

void amaze3()  {
    int i = 0;

    do {
        if (i++ % 2 == 0) printf("%d, ", i);
    }
    while (i < 10);
}

void amaze4(int i) {
    if (i == 10) return;
    if (i % 2 == 1) printf("%d, ", i);
    amaze4(++i);
}

void amaze5() {
    int i = 0;

    amaze:
        if (i == 10) return;
        if (i % 2 == 1) printf("%d, ", i);

    i++;
    goto amaze;
}

void amaze6() {
    for (int i = 0; i < 10; i++) {
        switch (i % 2) {
            case 1:
                printf("%d, ", i);
                break;
            default:
                break;
        }
    }
}

void amaze() {
    printf("amaze1: ");
    amaze1();
    printf("\n");
    printf("amaze2: ");
    amaze2();
    printf("\n");
    printf("amaze3: ");
    amaze3();
    printf("\n");
    printf("amaze4: ");
    amaze4(0);
    printf("\n");
    printf("amaze5: ");
    amaze5();
    printf("\n");
    printf("amaze6: ");
    amaze6();
    printf("\n");
}

int main(){
    amaze();
    return 0;
}