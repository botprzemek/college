#include <stdio.h>

struct X {
    short s;
    int i;
    char c;
};

struct Y {
    int i;
    char c;
    short s;
};

struct Z {
    int   i;
    short s;
    char  c;
};

int main() {
    struct X x;
    struct Y y;
    struct Z z;

    printf("Size of X: %llu,\n", sizeof(x));
    printf("Size of Y: %llu,\n", sizeof(y));
    printf("Size of Z: %llu,\n", sizeof(z));

    return 0;
}