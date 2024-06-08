#include <iostream>
#include <fstream>

#define LB_MIES 12

float dochody[LB_MIES];

void sortuj( float liczby[] );

void wyswietl_menu();

void wczytaj_dochody( float dochody[] );
void wyswietl_dochody( float dochody[] );

void srednia_suma_dochodow( float dochody[] );
void maksymalny_minimalny_dochod( float dochody[] );
void pod_nad_srednim_dochodem( float dochody[] );

int main() {
    int klawisz;
    puts( "Analiza rocznych dochodow" );
    do {
        wyswietl_menu();
        klawisz = getchar();
        fflush( stdin );

        switch( klawisz ) {
            case '1' : wczytaj_dochody( dochody );
                break;
            case '2' : wyswietl_dochody( dochody );
                break;
            case '3' : srednia_suma_dochodow( dochody );
                break;
            case '4' : maksymalny_minimalny_dochod( dochody );
                break;
            case '5' : sortuj( dochody );
                break;
            case '6' : pod_nad_srednim_dochodem( dochody );
                break;
            default:
                return EXIT_SUCCESS;
        } /* switch */
    }
    while (tolower(klawisz ) != 'z' );
}

void wyswietl_menu() {
    printf("1 - Wczytaj" << endl;
    printf("2 - Wyswietl" << endl;
    printf("3 - Srednia i suma" << endl;
    printf("4 - Minimalny i maksymalny" << endl;
    printf("5 - Od najmniejszego" << endl;
    printf("6 - Nad i pod srednia" << endl;
    printf("7 - Koniec" << endl;
}
void wczytaj_dochody( float dochody[] ) {
    ifstream dataFile("dane.txt");

    if(!dataFile.good()) {
        printf("Nie mozna wczytac pliku!" << endl;
        exit(EXIT_FAILURE);
    }
    int index = 0;
    string line;
    while (getline(dataFile, line)) {
        if(index > LB_MIES) continue;
        dochody[index] = stof(line);
        index++;
    }
}
void wyswietl_dochody( float dochody[] )
{
    printf(endl;
    for (int i = 0; i < LB_MIES; ++i) {
        printf(i+1 << ". " << dochody[i] << endl;
    }
    printf(endl;
}
void srednia_suma_dochodow( float dochody[] )
{
    printf(endl;
    float srednia, suma = 0;
    for (int i = 0; i < LB_MIES; ++i) suma += dochody[i];
    srednia = suma/LB_MIES;
    printf("Srednia: " << srednia << endl;
    printf("Suma: " << suma << endl;
    printf(endl;
}
void maksymalny_minimalny_dochod( float dochody[] )
{
    printf(endl;
    int min = dochody[0], max = dochody[0];
    for (int i = 0; i < LB_MIES; ++i) {
        if (dochody[i] > max) max = dochody[i];
        if(dochody[i] < min) min = dochody[i];
    }
    printf("Minimalny dochod: " << min << endl;
    printf("Maksymalny dochod: " << max << endl;
    printf(endl;
}
void sortuj( float dochody[] )
{
    float temp[LB_MIES];
    for (int i = 0; i < LB_MIES; ++i) temp[i] = dochody[i];
    for (int i = 0; i < LB_MIES-1; ++i) {
        for (int j = 0; j < LB_MIES-i-1; ++j) {
            if(temp[j] > temp[j+1]) swap(temp[j], temp[j + 1]);
        }
    }
    wyswietl_dochody(temp);
}
void pod_nad_srednim_dochodem( float dochody[] )
{
    printf(endl;
    float srednia = 0, wieksze = 0, wieksze_count = 0, mniejsze = 0, mniejsze_count = 0;
    for (int i = 0; i < LB_MIES; ++i) srednia += dochody[i];
    srednia = srednia/LB_MIES;

    for (int i = 0; i < LB_MIES; ++i) {
        if(dochody[i] > srednia) {
            wieksze_count++;
            wieksze += dochody[i];
        }
        if(dochody[i] < srednia) {
            mniejsze_count++;
            mniejsze += dochody[i];
        }
    }
    printf("Wieksze od sredniej: " << wieksze_count << " -> " << wieksze << endl;
    printf("Mniejsze od sredniej: %f -> %f", mniejsze_count, mniejsze);
}