#include <stdlib.h>

void set(int **array) {
    *(*array + 9) = 0;
}

int main() {
    int* array = (int*) malloc(10 * sizeof(int));

    set(&array);
    free(array);

    return 0;
}