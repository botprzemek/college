#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int input;
    int random = (rand() % 100) + 1;

    while(1) {
        printf("Input number: ");
        scanf("%d", &input);
        printf("- Input is");
        if (input == random) {
            printf(" equal to random\n");
            break;
        }
        else if (input < random) {
            printf(" too small\n");
            continue;
        }
        else printf(" too big\n");
    }
}