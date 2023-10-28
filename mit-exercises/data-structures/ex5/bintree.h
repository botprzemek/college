#ifndef BINTREE_H
#define BINTREE_H

typedef struct node {
    int id;
    char data;
    struct node* leftNode;
    struct node* rightNode;
} node;

void print(node* root);

node* insert(node* root, int id, char data);

//node* find(node* root, int id);

#endif