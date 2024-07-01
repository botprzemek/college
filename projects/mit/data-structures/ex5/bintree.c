#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "bintree.h"

void print(node *root) {
    printf("Printing Node (Id of %d):\n", root->id);
    printf("- Data: %c\n", root->data);
    printf("- Left node: %p\n", root->leftNode);
    printf("- Right node: %p\n", root->rightNode);
}

node* insert(node* root, int id, char data) {
    if (root == NULL || root->id == id) {
        root = (node*) malloc(sizeof(node));
        root->id = id;
        root->data = data;
        return root;
    }

    node* newNode = (node*) malloc(sizeof(node));

    newNode->id = id;
    newNode->data = data;
    newNode->leftNode = NULL;
    newNode->rightNode = NULL;

    if (id < root->id) root->leftNode = newNode;
    else root->rightNode = newNode;

    return root;
}

//node* find(node *root, int id) {
//    node* currentNode;
//    for (currentNode = root; currentNode != NULL; currentNode = currentNode->leftNode) {
//        if (currentNode->id == id) return currentNode;
//    }
//    for (currentNode = root; currentNode != NULL; currentNode = currentNode->rightNode) {
//        if (currentNode->id == id) return currentNode;
//    }
//    return NULL;
//}