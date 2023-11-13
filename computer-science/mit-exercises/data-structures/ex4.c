#include <stdlib.h>
#include <stdio.h>

typedef struct cell {
    char data;
    struct cell* next;
} cell;

cell* assign(char data) {
    cell* new = (cell*) malloc(sizeof(cell*));

    new->data = data;
    new->next = NULL;

    printf("Add: %c (%p)\n", new->data, new);

    return new;
}

void add(cell** root, char data) {
    if (*root != NULL) {
        for (cell* temp = *root; temp != NULL; temp = temp->next) {
            if (temp->next != NULL) continue;
            temp->next = assign(data);
            return;
        }
        return;
    }
    *root = assign(data);
}

char* get(cell** root, int index) {
    if (*root == NULL) {
        printf("Get: NULL (%d, 0x0)\n", index);
        return NULL;
    }

    int cellIndex = 0;

    for (cell* temp = *root; temp != NULL; temp = temp->next) {
        cellIndex++;

        if (cellIndex != index) continue;

        printf("Get: %c (%p)\n", temp->data, temp);

        return &(temp->data);
    }
    printf("Get: NULL (0x0)\n");
    return NULL;
}

void set(cell** root, int index, char data) {
    if (*root == NULL) return;

    int cellIndex = 0;

    for (cell* temp = *root; temp != NULL; temp = temp->next) {
        cellIndex++;

        if (cellIndex != index) continue;

        temp->data = data;

        printf("Set: %c (%p)\n", temp->data, temp);
        return;
    }
}

void delete(cell** root, int index) {
    if (*root == NULL) return;

    int cellIndex = 0;
    cell* old = NULL;

    for (cell* temp = *root; temp != NULL; temp = temp->next) {
        cellIndex++;

        if (cellIndex != index) {
            old = temp;
            continue;
        }

        old->next = temp->next;

        printf("Removed: %c (%p)\n", temp->data, temp);

        free(temp);

        return;
    }
}

int length(cell** root) {
    if (*root == NULL) return 0;

    cell* temp = *root;
    int iteration = 0;

    while(temp != NULL) {
        temp = temp->next;
        iteration++;
    }

    return iteration;
}


void display(cell** root) {
    cell* temp = *root;

    while(temp != NULL) {
        printf("Get: %c (%p)\n", temp->data, temp);
        temp = temp->next;
    }
}

int main() {
    cell* list = NULL;

    add(&list, 'A');
    add(&list, 'B');
    add(&list, 'C');

    delete(&list, 2);

    add(&list, 'D');

    printf("Length: %d\n", length(&list));
    display(&list);

    free(list);

    return 0;
}