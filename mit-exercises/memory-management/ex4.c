#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void fill(int **array, int *size) {
    srand(time(NULL));
    if (*(*array) <= 0) *array = (int*) malloc(*size * sizeof(int));

    for (int i = 0; i < *size; i++) {
        if (*(*array + i) <= 0) *(*array + i) = rand() % 323;
    }

    printf("Filled: ");

    for (int i = 0; i < *size; i++) {
        printf("%d, ", *(*array + i));
    }
}

int main() {
    int* array;
    int number1 = 0;
    int number2 = 0;

    printf("Enter original array size: ");
    scanf("%d", &number1);

    fill(&array, &number1);

    printf("\nEnter new array size: ");
    scanf("%d", &number2);

    fill(&array, &number2);

    free(array);

    return 0;
}