#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <stdlib.h>

struct Constant {
    char* name;
    char** words;
    int length;
    void (*addWord)(struct Constant* constant, char*);
    void (*setName)(struct Constant* constant, char*);
};

struct Constant* createConstant();

struct Constant* getConstant();

void freeConstant(struct Constant* constant) {
    for (int i = 0; i < constant->length; i++) {
        free(constant->words[i]);
    }
    free(constant->words);
    free(constant->name);
};

#endif