#include "stdio.h"
int average_measurement(double measurements[]);

int main() {
    double measurements[] = { 0.2, 0.3, 0.4 };
    printf("Average measurement: %d\n", average_measurement(measurements));
    return 0;
}

int average_measurement(double measurements[]) {
    size_t amount = sizeof(measurements) / sizeof(double);
    int sum = 0;
    double average = 0;

    for (int i = 0; i < amount; i++) {
        sum += measurements[i];
    }

    average = average / amount;

    for (int i = 0; i < amount; i++) {
        if (measurements[i] == average) sum++;
    }

    return sum;
}
