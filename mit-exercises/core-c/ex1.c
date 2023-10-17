#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* reverseArray(int* array, int length) {
    int temp;

    for (int i = 0; i < length/2; i++) {
        temp = array[i];
        array[i] = array[length - i - 1];
        array[length - i -1] = temp;
    }

    return array;
}

int* splitNumber(int number) {
    if (number < 0) return 0;

    int* array = (int*) malloc(sizeof(number));
    int length = 0;

    while (number != 0) {
        array[length] = number % 10;
        number /= 10;
        length++;
    }

    array = reverseArray(array, length);

    for (int i = 0; i < length; i++) {
        printf("%d\n", array[i]);
    }

    return array;
}

int* triangualarIteration(int* result, int size) {
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

int* triangualarRecursion(int* result, int size, int length) {
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
    int size = 3034;

    clock_t begin1 = clock();
    int* triangualar1 = triangualarIteration((int*) malloc(size), size);
    free(triangualar1);
    clock_t end1 = clock();

    clock_t begin2 = clock();
    int* triangualar2 = triangualarRecursion((int*) malloc(size), size, 0);
    free(triangualar2);
    clock_t end2 = clock();

    printf("Iteration (%fms)\n", (double)(end1 - begin1));
    printf("Recursion (%fms)\n", (double)(end2 - begin2));

    return 0;
}
