#include <stdio.h>

#include "Logger.h"

void title(const char* title) {
    printf("...%s...\n", title);
}

void message(const char* message) {
    printf("%s\n", message);
}

int getInt(const char* input) {
    int value;

    printf("Enter %s", input);
    scanf("%d", &value);
    printf("\n");

    return value;
}

char* getString(const char* input) {
    char* value;

    printf("Enter %s", input);
    scanf("%p", &value);

    return value;
}

struct Logger logger = {
    .title =  title,
    .message = message,
    .getInt = getInt,
    .getString = getString,
};

struct Logger* get() {
    return &logger;
}