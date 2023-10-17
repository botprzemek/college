#include <stdio.h>
#include <stdlib.h>

int arrayLength(const char* array) {
    int length = 0;
    while (array[length] != '\0') length++;
    return length;
}

char* stringCopy(const char* copy) {
    int length = arrayLength(copy);
    char* array = (char*) malloc(length);
    for (int i = 0; i < length; i++) array[i] = copy[i];
    return array;
}

int main() {
    char copy[] = "hakuna matata!";
    char* array = stringCopy(copy);

    printf("Result: '%s'", array);
    free(array);

    return 0;
}