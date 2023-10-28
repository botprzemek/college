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

    printf("Padding inside X: %lu bytes,\n", sizeof(x) - (sizeof(x.s) - sizeof(x.i) - sizeof(x.c)));
    printf("Padding inside Y: %lu bytes,\n", sizeof(y) - (sizeof(y.i) - sizeof(y.c) - sizeof(y.s)));
    printf("Padding inside Z: %lu bytes,\n", sizeof(z) - (sizeof(z.i) - sizeof(z.s) - sizeof(z.c)));

    return 0;
}