#include <stdio.h>

int fibonacci(int n);

int main() {
    int liczba = 10;

    // Pętlą wywołujemy dziesięć następnych liczb ciągu Fibonacciego
    for (int i = 0; i < liczba; i++) {
        printf("%d ", fibonacci(i));
    }

    return 0;
}

int fibonacci(int liczba) {
    // Jeśli wartość liczby jest równa zero zwracamy liczbę
    if (liczba <= 1) {
        return liczba;
    }

    // Zgodnie ze wzorem na ciąg dodajemy poprzednie dwie liczby
    return fibonacci(liczba-1) + fibonacci(liczba-2);
}