#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 128
#define PI 3.14159265358979323846

void wyswietl_menu();
void wyswietl_podmenu_figury();
void wyswietl_podmenu_funkcja_kwadratowa();
void wyswietl_podmenu_wspolczynniki();

float wczytaj_liczbe_f( char komunikat[] );

float kwadrat_liczby( float liczba );

float pole_kwadratu( float bok );
float obwod_kwadratu( float bok );

float pole_prostokata( float bok_a, float bok_b );
float obwod_prostokata( float bok_a, float bok_b );

float pole_trojkata( float podstawa, float wysokosc );
float obwod_trojkata( float bok_a, float bok_b, float bok_c );

float pole_trapezu( float bok_a, float bok_b, float wysokosc );
float obwod_trapezu( float bok_a, float bok_b, float bok_c, float bok_d );

float pole_kola( float promien );
float obwod_kola( float promien );


int main() {
    char klawisz;
    puts("\nWybierz opcje aby kontynuowac: ");

    do {
        puts("\n1. Kwadrat\n2. Prostokat\n3. Trojkat\n4. Trapez\n5. Kolo");
        printf("\nWybierz numer figury lub Z by wrocic: ");

        wyswietl_menu();
        klawisz = tolower( getchar() );
        while (getchar() != '\n');
        fflush( stdin );

        float bok, bok_a, bok_b, bok_c, bok_d, podstawa, wysokosc, promien;
        switch (klawisz)
        {
            case '1':
                printf("\nObliczenia dla kwadratu");
                bok = wczytaj_liczbe_f("\nPodaj dlugosc boku: ");
                printf("Pole: %f\nObwod: %f\n", pole_kwadratu(bok), obwod_kwadratu(bok));
                break;
            case '2':
                printf("\nObliczenia dla prostokata");
                bok_a = wczytaj_liczbe_f("\nPodaj dlugosc boku A: ");
                bok_b = wczytaj_liczbe_f("\nPodaj dlugosc boku B: ");
                printf("Pole: %f\nObwod: %f\n", pole_prostokata(bok_a, bok_b), obwod_prostokata(bok_a, bok_b));
                break;
            case '3':
                printf("\nObliczenia dla trojkata");
                bok_a = wczytaj_liczbe_f("\nPodaj dlugosc boku A: ");
                bok_b = wczytaj_liczbe_f("\nPodaj dlugosc boku B: ");
                bok_c = wczytaj_liczbe_f("\nPodaj dlugosc boku C: ");
                podstawa = wczytaj_liczbe_f("\nPodaj dlugosc podstawy: ");
                wysokosc = wczytaj_liczbe_f("\nPodaj wysokosc: ");
                printf("Pole: %f\nObwod: %f\n", pole_trojkata(podstawa, wysokosc), obwod_trojkata(bok_a, bok_b, bok_c));
                break;
            case '4':
                printf("\nObliczenia dla trapezu");
                bok_a = wczytaj_liczbe_f("\nPodaj dlugosc boku A: ");
                bok_b = wczytaj_liczbe_f("\nPodaj dlugosc boku B: ");
                bok_c = wczytaj_liczbe_f("\nPodaj dlugosc boku C: ");
                bok_d = wczytaj_liczbe_f("\nPodaj dlugosc boku D: ");
                wysokosc = wczytaj_liczbe_f("\nPodaj wysokosc: ");
                printf("Pole: %f\nObwod: %f\n", pole_trapezu(bok_a, bok_b, wysokosc), obwod_trapezu(bok_a, bok_b, bok_c, bok_d));
                break;
            case '5':
                printf("\nObliczenia dla kola");
                promien = wczytaj_liczbe_f("\nPodaj promien: ");
                printf("Pole: %f\nObwod: %f\n", pole_kola(promien), obwod_kola(promien));
                break;
            case 'z':
                break;
            default:
                putchar('\a');
                break;
        }
    }
    while (klawisz != 'z');

    return EXIT_SUCCESS;
}

void wyswietl_menu()
{
    puts("\n1. Figur\n2. Funkcji kwadratowej\n3. Wspolczynnikow");
    printf("\nWybierz numer opcji lub Z by zakonczyc: ");
}

float wczytaj_liczbe_f( char komunikat[] )
{
    char bufor_tekstowy[ MAX_LEN ];
    printf( komunikat );
    fgets( bufor_tekstowy, MAX_LEN, stdin ) ;
    return atof( bufor_tekstowy );
}

float kwadrat_liczby( float liczba ) {
    return liczba * liczba;
}

float pole_kwadratu( float bok )
{
    return pole_prostokata( bok, bok );
}

float obwod_kwadratu( float bok )
{
    return obwod_prostokata( bok, bok );
}

float pole_prostokata( float bok_a, float bok_b )
{
    return bok_a * bok_b;
}

float obwod_prostokata( float bok_a, float bok_b )
{
    return 2 * ( bok_a + bok_b );
}

float pole_trojkata( float podstawa, float wysokosc )
{
    return podstawa * wysokosc;
}

float obwod_trojkata( float bok_a, float bok_b, float bok_c )
{
    return bok_a + bok_b + bok_c;
}

float pole_trapezu( float bok_a, float bok_b, float wysokosc )
{
    return (bok_a + bok_b) * 0.5 * wysokosc;
}

float obwod_trapezu( float bok_a, float bok_b, float bok_c, float bok_d )
{
    return bok_a + bok_b + bok_c + bok_d;
}

float pole_kola( float promien )
{
    return kwadrat_liczby(promien) * PI;
}

float obwod_kola( float promien )
{
    return 2 * promien * PI;
}