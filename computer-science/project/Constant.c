#include <printf.h>
#include "Constant.h"

void word(struct Constant* constant, char* word) {
    constant->words[constant->length] = word;
    constant->length++;
}

void name(struct Constant* constant, char* name) {
    constant->name = name;
}

struct Constant constant = {
    .length = 0,
    .name = NULL,
    .words = NULL,
    .addWord = word,
    .setName = name
};

struct Constant* createConstant() {
    if (constant.words == NULL) constant.words = (char**)malloc(20 * sizeof(char*));
    return &constant;
}

struct Constant* getConstant() {
    return &constant;
}