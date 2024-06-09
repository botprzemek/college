#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

struct element {
    int liczba;
    struct element* nastepny;
};

struct element* pierwszy = NULL;

void dodaj(int liczba) {
    struct element* nowyElement = (struct element*) malloc(sizeof(struct element));

    nowyElement->liczba = liczba;
    nowyElement->nastepny = pierwszy;

    pierwszy = nowyElement;
}

int pobierz() {
    if (pierwszy == NULL) {
        printf("Stos jest pusty.\n");
        return -1;
    }

    int liczba = pierwszy->liczba;
    struct element* temp = pierwszy;

    pierwszy = pierwszy->nastepny;

    free(temp);
    return liczba;
}

void wyswietlStos() {
    struct element* temp = pierwszy;

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
        printf("1. Dodaj na stos\n");
        printf("2. Pobierz ze stosu\n");
        printf("3. Wyswietl stos\n");
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
                liczba = pobierz();

                if (liczba != -1) {
                    printf("Pobrano liczbe: %d\n", liczba);
                }

                break;
            case '3':
                wyswietlStos();
                break;
            case '4':
                return 0;
            default:
                printf("Nieprawidlowy wybor\n");
        }
    }
}
