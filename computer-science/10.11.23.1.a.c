#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int input;
    int random = (rand() % 100) + 1;

    start:
        printf("Input number: ");
        scanf("%d", &input);
        printf("- Input is");
        if (input == random) {
            printf(" equal to random\n");
            return 0;
        }
        if (input < random) {
            printf(" too small\n");
            goto start;
        }
        printf(" too big\n");
        goto start;
}