#include <stdio.h>

union number {
  int value;
  unsigned char bytes[4];
};

int main() {
    union number number;
    number.value = 257;
    printf("%d as bytes ", number.value);
    for (int i = 0; i < sizeof(number.bytes); i++) printf("- %d ", *(number.bytes + i));
    return 0;
}