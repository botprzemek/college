#include <stdio.h>
#include <ctype.h>

#define LB_MIES 12

float dochody[LB_MIES] =  {
    10523.45,
    8720.89,
    15123.67,
    19345.78,
    13245.56,
    7864.12,
    14987.34,
    23456.78,
    17450.67,
    11678.90,
    9812.34,
    14234.56
};

void sortuj(float liczby[]);

void wyswietl_menu();

void wczytaj_dochody(float dochody[]);

void wyswietl_dochody(float dochody[]);

void srednia_suma_dochodow(float dochody[]);

void maksymalny_minimalny_dochod(float dochody[]);

void pod_nad_srednim_dochodem(float dochody[]);

int main() {
    int klawisz;

    puts("Analiza rocznych dochodow\n");

    do {
        wyswietl_menu();

        klawisz = getchar();
        fflush(stdin);

        switch (klawisz) {
            case '1' :
                wczytaj_dochody(dochody);
                break;
            case '2' :
                wyswietl_dochody(dochody);
                break;
            case '3' :
                srednia_suma_dochodow(dochody);
                break;
            case '4' :
                maksymalny_minimalny_dochod(dochody);
                break;
            case '5' :
                sortuj(dochody);
                break;
            case '6' :
                pod_nad_srednim_dochodem(dochody);
                break;
            default:
                return 0;
        }
    }
    while (tolower(klawisz) != 'z');
}

void wyswietl_menu() {
    printf("1 - Wczytaj\n");
    printf("2 - Wyswietl\n");
    printf("3 - Srednia i suma\n");
    printf("4 - Minimalny i maksymalny\n");
    printf("5 - Od najmniejszego\n");
    printf("6 - Nad i pod srednia\n");
    printf("7 - Koniec\n");
}

void wyswietl_dochody(float dochody[]) {
    for (int i = 0; i < LB_MIES; ++i) {
        printf("%d. %f \n", i + 1, dochody[i]);
    }
}

void srednia_suma_dochodow(float dochody[]) {
    float srednia, suma = 0;

    for (int i = 0; i < LB_MIES; ++i) {
        suma += dochody[i];
    }

    srednia = suma / LB_MIES;

    printf("Srednia: %f\n", srednia);
    printf("Suma: %f\n", suma);
}

void maksymalny_minimalny_dochod(float dochody[]) {
    int min = dochody[0], max = dochody[0];

    for (int i = 0; i < LB_MIES; ++i) {
        if (dochody[i] > max) max = dochody[i];
        if (dochody[i] < min) min = dochody[i];
    }

    printf("Minimalny dochod: %d\n", min);
    printf("Maksymalny dochod: %d\n", max);
}

void sortuj(float dochody[]) {
    float temp[LB_MIES];
    for (int i = 0; i < LB_MIES; ++i) temp[i] = dochody[i];
    for (int i = 0; i < LB_MIES - 1; ++i) {
        for (int j = 0; j < LB_MIES - i - 1; ++j) {
            if (temp[j] > temp[j + 1]) {
                float nowa = temp[j];

                temp[j] = temp[j + 1];
                temp[j + 1] = nowa;
            }
        }
    }
    wyswietl_dochody(temp);
}

void pod_nad_srednim_dochodem(float dochody[]) {
    float srednia = 0;
    float wieksze = 0;
    float mniejsze = 0;

    int wieksze_count = 0;
    int mniejsze_count = 0;

    for (int i = 0; i < LB_MIES; ++i) {
        srednia += dochody[i];
    }

    srednia = srednia / LB_MIES;

    for (int i = 0; i < LB_MIES; ++i) {
        if (dochody[i] > srednia) {
            wieksze_count++;
            wieksze += dochody[i];
        }

        if (dochody[i] < srednia) {
            mniejsze_count++;
            mniejsze += dochody[i];
        }
    }

    printf("Wieksze od sredniej: %d -> %f", wieksze_count, wieksze);
    printf("Mniejsze od sredniej: %d -> %f", mniejsze_count, mniejsze);
}