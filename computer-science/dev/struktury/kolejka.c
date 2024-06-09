#include <stdio.h>
#include <stdlib.h>

struct element {
    int liczba;
    struct element* nastepny;
};

struct element* front = NULL;
struct element* rear = NULL;

void enqueue(int liczba) {
    struct element* nowyElement = (struct element*)malloc(sizeof(struct element));
    nowyElement->liczba = liczba;
    nowyElement->nastepny = NULL;
    if (rear == NULL) {
        front = rear = nowyElement;
        return;
    }
    rear->nastepny = nowyElement;
    rear = nowyElement;
}

int dequeue() {
    if (front == NULL) {
        printf("Kolejka jest pusta.\n");
        return -1;
    }
    int liczba = front->liczba;
    struct element* temp = front;
    front = front->nastepny;
    if (front == NULL) {
        rear = NULL;
    }
    free(temp);
    return liczba;
}

void wyswietlKolejke() {
    struct element* temp = front;
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
        printf("1. Dodaj do kolejki\n");
        printf("2. Pobierz z kolejki\n");
        printf("3. Wyswietl kolejke\n");
        printf("4. Wyjdz\n");
        printf("Wybor: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Podaj liczbe: ");
                scanf("%d", &liczba);
                enqueue(liczba);
                break;
            case 2:
                liczba = dequeue();
                if (liczba != -1) {
                    printf("Pobrano liczbe: %d\n", liczba);
                }
                break;
            case 3:
                wyswietlKolejke();
                break;
            case 4:
                return 0;
            default:
                printf("Nieprawidlowy wybor.\n");
        }
    }
    return 0;
}
