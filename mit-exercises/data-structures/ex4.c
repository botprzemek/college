#include <stdlib.h>
#include <stdio.h>

typedef struct cell {
    int index;
    char data;
    struct cell* next;
} cell;

cell* assign(cell* root, char data) {
    cell* new = (cell*) malloc(sizeof(cell*));

    if (root == NULL) new->index = 1;
    else new->index = root->index + 1;

    new->data = data;
    new->next = NULL;

    printf("Add: %c (#%d, %p)\n", new->data, new->index, new);

    return new;
}

void add(cell* *root, char data) {
    if (*root != NULL) {
        for (cell* temp = *root; temp != NULL; temp = temp->next) {
            if (temp->next != NULL) continue;
            temp->next = assign(temp, data);
            return;
        }
        return;
    }
    *root = assign(*root, data);
}

char* get(cell* *root, int index) {
    if (*root == NULL) {
        printf("Get: NULL (#%d, 0x0)\n", index);
        return NULL;
    }
    for (cell* temp = *root; temp != NULL; temp = temp->next) {
        if (temp->index != index) continue;
        printf("Get: %c (#%d, %p)\n", temp->data, temp->index, temp);
        return &(temp->data);
    }
    printf("Get: NULL (#%d, 0x0)\n", index);
    return NULL;
}

void set(cell* *root, int index, char data) {
    if (*root == NULL) return;
    for (cell* temp = *root; temp != NULL; temp = temp->next) {
        if (temp->index != index) continue;
        temp->data = data;
        printf("Set: %c (#%d, %p)\n", temp->data, temp->index, temp);
        return;
    }
}

void delete(cell* *root, int index) {
    if (*root == NULL) return;
    cell* old = NULL;
    for (cell* temp = *root; temp != NULL; temp = temp->next) {
        if (temp->index != index) {
            old = temp;
            continue;
        }
        old->next = temp->next;
        printf("Removed: %c (#%d, %p)\n", temp->data, temp->index, temp);
        return;
    }
}

int main() {
    cell* list = NULL;

    add(&list, 'A');
    add(&list, 'B');
    add(&list, 'C');

    get(&list, 1);

    set(&list, 2, 'X');

    get(&list, 2);

    delete(&list, 2);

    get(&list, 2);

    free(list);

    return 0;
}