#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* reverseArray(int **array, int length) {
    int temp;

    for (int i = 0; i < length/2; i++) {
        temp = array[i];
        array[i] = array[length - i - 1];
        array[length - i -1] = temp;
    }

    return array;
}

int* triangualarIteration(int size) {
    int* result = (int*) malloc(((int) size / 3) * sizeof(int));
    if (size < 0) return result;

    int length = 0;

    for (int i = 0; i <= size; i++) {
        if (i % 3 == 0) {
            result[length++] = i;
            i += 3;
        }
    }

    return result;
}

int* triangualarRecursion(int **result, int size, int length) {
    if (size < 0) return result;
    if (size % 3 != 0) return triangualarRecursion(result, --size, length);
    if (size != 0) {
        result[length++] = size--;
        return triangualarRecursion(result, size, length);
    }

    result[length++] = size;
    result = reverseArray(result, length);

    return result;
}

int main() {
    int size = 0;

    printf("Enter numbers size: ");
    scanf("%d", &size);

    clock_t begin1 = clock();
    int* triangualar1 = triangualarIteration(size);
    free(triangualar1);
    clock_t end1 = clock();

    clock_t begin2 = clock();
    int* triangualar2 = triangualarRecursion((int*) malloc(((int) size / 3) * sizeof(int)), size, 0);
    free(triangualar2);
    clock_t end2 = clock();

    printf("\nIteration (%fms)\n", (double)(end1 - begin1));
    printf("Recursion (%fms)\n", (double)(end2 - begin2));

    return 0;
}
