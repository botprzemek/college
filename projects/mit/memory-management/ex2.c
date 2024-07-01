#include <stdio.h>
#include <stdlib.h>

int arrayLength(const char* array) {
    int length = 0;
    while (*(array + length) != '\0') length++;
    return ++length;
}

void stringCopy(char **array, const char* copy) {
    int length = arrayLength(copy);
    *array = (char*) malloc(length * sizeof(char));
    for (int i = 0; i < length; i++) *(*array + i) = *(copy + i);
}

int main() {
    char *array;

    stringCopy(&array, "hakuna matata!");
    printf("Result: '%s'", array);
    free(array);

    return 0;
}