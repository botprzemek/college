#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int arrayLength(const int* numbers) {
    int length = 0;
    while (numbers[length] != '\0') {
        printf("Array length: %d", numbers[length]);
        length++;
    }
    return length;
}

void fillRandom(int* array) {
    int length = arrayLength(array);
    printf("Length: %d", length);
    srand(time(NULL));
    for (int i = 0; i < length; i++) array[i] = rand() % 3;
}

void sortInsert(int* array) {
    int temp;
    int j;

    int length = arrayLength(array);

    for (int i = 1; i < length; i++) {
        temp = array[i];
        j=i-1;

        while (temp < array[j] && j>=0) {
            array[j+1] = array[j];
            j--;
        }

        array[j+1] = temp;
    }
}

int main() {
    int number;

    printf("Enter an integer n: ");
    scanf("%d", &number);

    int* array = (char*) malloc(number);

    fillRandom(array);

    printf("The unsorted array is: ");
    for (int i = 0; i < number; i++) printf("%d ", array[i]);

    sortInsert(array);

    printf("\nThe sorted array is: ");
    for (int i = 0; i < number; i++) printf("%d ", array[i]);

    free(array);

    return 0;
}
