#include <stdio.h>
#include <stdlib.h>
#include "ex5/bintree.h"

int main() {
    node* root = NULL;

    root = insert(root, 1, 'A');

    insert(root, 2, 'B');
    insert(root, 3, 'C');

//    int id = 6;
//
//    node* found = find(root, id);
//
//    if (found != NULL) {
//        print(found);
//        return 0;
//    }
//
//    printf("Printing Node (Id of %d):\n- Not found", id);

    free(root);

	return 0;
}
