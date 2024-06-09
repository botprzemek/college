#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define N 20

struct ksiazka {
    char tytul[80];
    char autor[80];
    int liczbaStron;
    bool wypozyczona;
    bool rekordSkasowany;
};

struct ksiazka bazaDanych[N];

void dodajKsiazke() {
    for (int i = 0; i < N; i++) {
        if (bazaDanych[i].rekordSkasowany) {
            printf("Podaj tytul: ");
            scanf(" %[^\n]", bazaDanych[i].tytul);
            printf("Podaj autora: ");
            scanf(" %[^\n]", bazaDanych[i].autor);
            printf("Podaj liczbe stron: ");
            scanf("%d", &bazaDanych[i].liczbaStron);
            bazaDanych[i].wypozyczona = false;
            bazaDanych[i].rekordSkasowany = false;
            printf("Ksiazka dodana.\n");
            return;
        }
    }
    printf("Brak miejsca na nowe ksiazki.\n");
}

void edytujKsiazke(int index) {
    if (index >= 0 && index < N && !bazaDanych[index].rekordSkasowany) {
        printf("Podaj nowy tytul: ");
        scanf(" %[^\n]", bazaDanych[index].tytul);
        printf("Podaj nowego autora: ");
        scanf(" %[^\n]", bazaDanych[index].autor);
        printf("Podaj nowa liczbe stron: ");
        scanf("%d", &bazaDanych[index].liczbaStron);
        printf("Ksiazka zaktualizowana.\n");
    } else {
        printf("Nieprawidlowy indeks lub ksiazka usunieta.\n");
    }
}

void usunKsiazke(int index) {
    if (index >= 0 && index < N && !bazaDanych[index].rekordSkasowany) {
        bazaDanych[index].rekordSkasowany = true;
        printf("Ksiazka usunieta.\n");
    } else {
        printf("Nieprawidlowy indeks lub ksiazka juz usunieta.\n");
    }
}

void wypozyczKsiazke(int index) {
    if (index >= 0 && index < N && !bazaDanych[index].rekordSkasowany && !bazaDanych[index].wypozyczona) {
        bazaDanych[index].wypozyczona = true;
        printf("Ksiazka wypozyczona.\n");
    } else {
        printf("Nieprawidlowy indeks, ksiazka usunieta lub juz wypozyczona.\n");
    }
}

void zwrocKsiazke(int index) {
    if (index >= 0 && index < N && !bazaDanych[index].rekordSkasowany && bazaDanych[index].wypozyczona) {
        bazaDanych[index].wypozyczona = false;
        printf("Ksiazka zwrocona.\n");
    } else {
        printf("Nieprawidlowy indeks, ksiazka usunieta lub nie byla wypozyczona.\n");
    }
}

void wyswietlWszystkieKsiazki() {
    for (int i = 0; i < N; i++) {
        if (!bazaDanych[i].rekordSkasowany) {
            printf("Indeks: %d, Tytul: %s, Autor: %s, Liczba stron: %d, Wypozyczona: %s\n", i, bazaDanych[i].tytul, bazaDanych[i].autor, bazaDanych[i].liczbaStron, bazaDanych[i].wypozyczona ? "Tak" : "Nie");
        }
    }
}

void wyswietlKsiazkiWypozyczone() {
    for (int i = 0; i < N; i++) {
        if (!bazaDanych[i].rekordSkasowany && bazaDanych[i].wypozyczona) {
            printf("Indeks: %d, Tytul: %s, Autor: %s, Liczba stron: %d\n", i, bazaDanych[i].tytul, bazaDanych[i].autor, bazaDanych[i].liczbaStron);
        }
    }
}

int main() {
    for (int i = 0; i < N; i++) {
        bazaDanych[i].rekordSkasowany = true; // oznacza, że miejsce jest wolne
    }

    int choice, index;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Dodaj ksiazke\n");
        printf("2. Edytuj ksiazke\n");
        printf("3. Usun ksiazke\n");
        printf("4. Wypozycz ksiazke\n");
        printf("5. Zwroc ksiazke\n");
        printf("6. Wyswietl wszystkie ksiazki\n");
        printf("7. Wyswietl wypozyczone ksiazki\n");
        printf("8. Wyjdz\n");
        printf("Wybor: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                dodajKsiazke();
                break;
            case 2:
                printf("Podaj indeks ksiazki do edycji: ");
                scanf("%d", &index);
                edytujKsiazke(index);
                break;
            case 3:
                printf("Podaj indeks ksiazki do usuniecia: ");
                scanf("%d", &index);
                usunKsiazke(index);
                break;
            case 4:
                printf("Podaj indeks ksiazki do wypozyczenia: ");
                scanf("%d", &index);
                wypozyczKsiazke(index);
                break;
            case 5:
                printf("Podaj indeks ksiazki do zwrocenia: ");
                scanf("%d", &index);
                zwrocKsiazke(index);
                break;
            case 6:
                wyswietlWszystkieKsiazki();
                break;
            case 7:
                wyswietlKsiazkiWypozyczone();
                break;
            case 8:
                return 0;
            default:
                printf("Nieprawidlowy wybor.\n");
        }
    }
    return 0;
}
