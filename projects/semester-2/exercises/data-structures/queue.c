#include <stdio.h>
#include <stdlib.h>

struct element {
    int liczba;
    struct element* nastepny;
};

struct element* przod = NULL;
struct element* tyl = NULL;

void dodaj(int liczba) {
    struct element* nowyElement = (struct element*) malloc(sizeof(struct element));

    nowyElement->liczba = liczba;
    nowyElement->nastepny = NULL;

    if (tyl == NULL) {
        przod = tyl = nowyElement;
        return;
    }

    tyl->nastepny = nowyElement;
    tyl = nowyElement;
}

int usun() {
    if (przod == NULL) {
        printf("Kolejka jest pusta.\n");
        return -1;
    }

    int liczba = przod->liczba;
    struct element* temp = przod;

    przod = przod->nastepny;

    if (przod == NULL) {
        tyl = NULL;
    }

    free(temp);
    return liczba;
}

void wyswietl() {
    struct element* temp = przod;

    while (temp != NULL) {
        printf("%d ", temp->liczba);
        temp = temp->nastepny;
    }

    printf("\n");
}

int main() {
    int wybor, liczba;

    while (1) {
        printf("Menu:\n");
        printf("1. Dodaj do kolejki\n");
        printf("2. Pobierz z kolejki\n");
        printf("3. Wyswietl kolejke\n");
        printf("4. Wyjdz\n");
        printf("Wybor: ");

        wybor = getchar();
        fflush(stdin);

        switch (wybor) {
            case '1':
                printf("Podaj liczbe: ");

                scanf("%d", &liczba);
                dodaj(liczba);

                break;
            case '2':
                liczba = usun();

                if (liczba != -1) {
                    printf("Pobrano liczbe: %d\n", liczba);
                }

                break;
            case '3':
                wyswietl();
                break;
            case '4':
                return 0;
            default:
                printf("Nieprawidlowy wybor\n");
        }
    }
}
