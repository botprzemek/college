#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct matrix {
    int width;
    int height;
    char** data;
} matrix;

void create(matrix** matrix) {
    (*matrix)->data = malloc(((*matrix)->height + 1) * sizeof(char));
    for (int i = 0; i < (*matrix)->height + 1; i++) {
        (*matrix)->data[i] = malloc((*matrix)->width * sizeof(char));
        for (int j = 0; j < (*matrix)->width; j++) {
            (*matrix)->data[i][j] = rand() % 25 + 'a';
        }
    }
}

void print(matrix** matrix) {
    for (int i = 1; i <= (*matrix)->height; i++) {
        for (int j = 0; j < (*matrix)->width; j++) {
            printf("[%d.%d] = %c, ", i , j, (*matrix)->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    matrix* matrix = malloc(2 * sizeof(int) + sizeof(char**));

    printf("Insert width: ");
    scanf("%d", &(matrix->width));

    printf("Insert height: ");
    scanf("%d", &(matrix->height));

    create(&matrix);
    print(&matrix);

    return 0;
}