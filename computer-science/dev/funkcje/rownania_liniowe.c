float w( float punkt_a_1, float punkt_b_1, float punkt_a_2, float punkt_b_2 );
float wx( float punkt_c_1, float punkt_b_1, float punkt_c_2, float punkt_b_2 );
float wy( float punkt_a_1, float punkt_c_1, float punkt_a_2, float punkt_c_2 );

int main()
{
    return 0;
}

float w( float punkt_a_1, float punkt_b_1, float punkt_a_2, float punkt_b_2 )
{
    return ( punkt_a_1 * punkt_b_2 ) - ( punkt_b_1 * punkt_a_2 );
}

float wx( float punkt_c_1, float punkt_b_1, float punkt_c_2, float punkt_b_2 )
{
    return ( punkt_c_1 * punkt_b_2 ) - ( punkt_b_1 * punkt_c_2 );
}

float wy( float punkt_a_1, float punkt_c_1, float punkt_a_2, float punkt_c_2 )
{
    return ( punkt_a_1 * punkt_c_2 ) - ( punkt_c_1 * punkt_a_2 );
}
