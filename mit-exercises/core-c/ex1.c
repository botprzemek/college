#include <stdio.h>
#include <stdlib.h>

void triangualarIteration(int **array, int *size) {
    *array = (int*) malloc(*size * sizeof(int));
    for (int i = 0; i < *size; i++) *(*array + i) = i * (i + 1) / 2;
}

int main() {
    int size = 0;
    int* triangualar1;

    printf("Enter numbers size: ");
    scanf("%d", &size);

    triangualarIteration(&triangualar1, &size);
    free(triangualar1);

    return 0;
}