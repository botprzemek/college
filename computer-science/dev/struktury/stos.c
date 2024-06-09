#include <stdio.h>
#include <stdlib.h>

struct element {
    int liczba;
    struct element* nastepny;
};

struct element* top = NULL;

void push(int liczba) {
    struct element* nowyElement = (struct element*)malloc(sizeof(struct element));
    nowyElement->liczba = liczba;
    nowyElement->nastepny = top;
    top = nowyElement;
}

int pop() {
    if (top == NULL) {
        printf("Stos jest pusty.\n");
        return -1;
    }
    int liczba = top->liczba;
    struct element* temp = top;
    top = top->nastepny;
    free(temp);
    return liczba;
}

void wyswietlStos() {
    struct element* temp = top;
    while (temp != NULL) {
        printf("%d ", temp->liczba);
        temp = temp->nastepny;
    }
    printf("\n");
}

int main() {
    int choice, liczba;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Dodaj na stos\n");
        printf("2. Pobierz ze stosu\n");
        printf("3. Wyswietl stos\n");
        printf("4. Wyjdz\n");
        printf("Wybor: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Podaj liczbe: ");
                scanf("%d", &liczba);
                push(liczba);
                break;
            case 2:
                liczba = pop();
                if (liczba != -1) {
                    printf("Pobrano liczbe: %d\n", liczba);
                }
                break;
            case 3:
                wyswietlStos();
                break;
            case 4:
                return 0;
            default:
                printf("Nieprawidlowy wybor.\n");
        }
    }
    return 0;
}
