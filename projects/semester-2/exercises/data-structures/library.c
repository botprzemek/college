#include <stdio.h>
#include <stdbool.h>

#define N 20

struct ksiazka {
    char tytul[80];
    char autor[80];
    int liczbaStron;
    bool wypozyczona;
    bool rekordSkasowany;
};

struct ksiazka biblioteka[N];

void dodaj();

void edytuj(int index);

void usun(int index);

void wypozycz(int index);

void zwroc(int index);

void wyswietl_wszystkie();

void wyswietl_wypozyczone();

int main() {
    for (int i = 0; i < N; i++) {
        biblioteka[i].rekordSkasowany = true;
    }

    int wybor, index;

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

        wybor = getchar();
        fflush(stdin);

        switch (wybor) {
            case 1:
                dodaj();
                break;
            case 2:
                printf("Podaj indeks ksiazki do edycji: ");
                scanf("%d", &index);
                edytuj(index);
                break;
            case 3:
                printf("Podaj indeks ksiazki do usuniecia: ");
                scanf("%d", &index);
                usun(index);
                break;
            case 4:
                printf("Podaj indeks ksiazki do wypozyczenia: ");
                scanf("%d", &index);
                wypozycz(index);
                break;
            case 5:
                printf("Podaj indeks ksiazki do zwrocenia: ");
                scanf("%d", &index);
                zwroc(index);
                break;
            case 6:
                wyswietl_wszystkie();
                break;
            case 7:
                wyswietl_wypozyczone();
                break;
            case 8:
                return 0;
            default:
                printf("Nieprawidlowy wybor.\n");
        }
    }
    return 0;
}

void dodaj() {
    for (int i = 0; i < N; i++) {
        if (!biblioteka[i].rekordSkasowany) return;

        printf("Podaj tytul: ");
        scanf(" %[^\n]", biblioteka[i].tytul);
        printf("Podaj autora: ");
        scanf(" %[^\n]", biblioteka[i].autor);
        printf("Podaj liczbe stron: ");
        scanf("%d", &biblioteka[i].liczbaStron);

        biblioteka[i].wypozyczona = false;
        biblioteka[i].rekordSkasowany = false;

        printf("Ksiazka dodana.\n");
    }

    printf("Brak miejsca na nowe ksiazki.\n");
}

void edytuj(int index) {
    if (index >= 0 && index < N && !biblioteka[index].rekordSkasowany) {
        printf("Podaj nowy tytul: ");
        scanf(" %[^\n]", biblioteka[index].tytul);
        printf("Podaj nowego autora: ");
        scanf(" %[^\n]", biblioteka[index].autor);
        printf("Podaj nowa liczbe stron: ");
        scanf("%d", &biblioteka[index].liczbaStron);
        printf("Ksiazka zaktualizowana.\n");
    } else {
        printf("Nieprawidlowy indeks lub ksiazka usunieta.\n");
    }
}

void usun(int index) {
    if (index >= 0 && index < N && !biblioteka[index].rekordSkasowany) {
        biblioteka[index].rekordSkasowany = true;
        printf("Ksiazka usunieta.\n");
    } else {
        printf("Nieprawidlowy indeks lub ksiazka juz usunieta.\n");
    }
}

void wypozycz(int index) {
    if (index >= 0 && index < N && !biblioteka[index].rekordSkasowany && !biblioteka[index].wypozyczona) {
        biblioteka[index].wypozyczona = true;
        printf("Ksiazka wypozyczona.\n");
    } else {
        printf("Nieprawidlowy indeks, ksiazka usunieta lub juz wypozyczona.\n");
    }
}

void zwroc(int index) {
    if (index >= 0 && index < N && !biblioteka[index].rekordSkasowany && biblioteka[index].wypozyczona) {
        biblioteka[index].wypozyczona = false;
        printf("Ksiazka zwrocona.\n");
    } else {
        printf("Nieprawidlowy indeks, ksiazka usunieta lub nie byla wypozyczona.\n");
    }
}

void wyswietl_wszystkie() {
    for (int i = 0; i < N; i++) {
        if (!biblioteka[i].rekordSkasowany) {
            printf("Indeks: %d, Tytul: %s, Autor: %s, Liczba stron: %d, Wypozyczona: %s\n", i, biblioteka[i].tytul,
                   biblioteka[i].autor, biblioteka[i].liczbaStron, biblioteka[i].wypozyczona ? "Tak" : "Nie");
        }
    }
}

void wyswietl_wypozyczone() {
    for (int i = 0; i < N; i++) {
        if (!biblioteka[i].rekordSkasowany && biblioteka[i].wypozyczona) {
            printf("Indeks: %d, Tytul: %s, Autor: %s, Liczba stron: %d\n", i, biblioteka[i].tytul, biblioteka[i].autor,
                   biblioteka[i].liczbaStron);
        }
    }
}
