#include <math.h>
float kwadrat_liczby( float liczba );

float delta( float wspolczynnik_a, float wspolczynnik_b, float wspolczynnik_c );
float x0( float wspolczynnik_a, float wspolczynnik_b );
float x1( float wspolczynnik_a, float wspolczynnik_b, float wspolczynnik_c );
float x2( float wspolczynnik_a, float wspolczynnik_b, float wspolczynnik_c );

int main()
{
    return 0;
}

float kwadrat_liczby( float liczba ) {
    return liczba * liczba;
}

float delta( float wspolczynnik_a, float wspolczynnik_b, float wspolczynnik_c )
{
    return kwadrat_liczby( wspolczynnik_b ) - ( 4 * wspolczynnik_a * wspolczynnik_c );
}

float x0( float wspolczynnik_a, float wspolczynnik_b )
{
    return -1 * wspolczynnik_b * 0.5 * wspolczynnik_a;
}

float x1( float wspolczynnik_a, float wspolczynnik_b, float wspolczynnik_c )
{
    return ( -1 * wspolczynnik_b + sqrt( delta( wspolczynnik_a, wspolczynnik_b, wspolczynnik_c ) ) ) * 0.5 * wspolczynnik_a;
}

float x2( float wspolczynnik_a, float wspolczynnik_b, float wspolczynnik_c )
{
    return ( -1 * wspolczynnik_b - sqrt( delta( wspolczynnik_a, wspolczynnik_b, wspolczynnik_c ) ) ) * 0.5 * wspolczynnik_a;
}
