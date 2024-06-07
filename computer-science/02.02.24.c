#include <stdio.h>
#include <stdlib.h>

int len(const int *arr) {
    int len = 0;

    while (arr[len] != 0) {
        len++;
    }

    return len;
}

void sqr(int *num) {
    *num *= *num;
}

int main() {
    int* nums = malloc(4 * sizeof(int));

    nums[0] = 4;
    nums[1] = 2;
    nums[2] = 1;
    nums[3] = 6;

    for (int i = 0; i < len(nums); i++) {
        printf("Number: %d ", nums[i]);

        sqr(&nums[i]);

        printf("(Squared: %d),\n", nums[i]);
    }

    free(nums);

    return 0;
}