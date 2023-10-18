#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int arrayLength(const int* numbers) {
    int length = 0;
    while (*(numbers + length) != '\0') length++;
    return length;
}

void fillRandom(int* array, int *size) {
    srand(time(NULL));
    for (int i = 0; i < *size; i++) *(array + i) = rand() % 323;
}

void sortInsert(int* array) {
    int length = arrayLength(array);
    int temp;
    int j;

    for (int i = 1; i < length; i++) {
        temp = *(array + i);
        j=i-1;

        while (temp < array[j] && j>=0) {
            *(array + j + 1) = *(array + j);
            j--;
        }

        *(array + j + 1) = temp;
    }
}

int main() {
    int number = 0;

    printf("Enter an integer n: ");
    scanf("%d", &number);

    int* array = (int*) malloc(number * sizeof(int));

    fillRandom(array, &number);
    sortInsert(array);

    printf("Generated sorted array is: ");
    for (int i = 0; i < number; i++) printf("%d ", *(array + i));

    free(array);

    return 0;
}