void sierpinski(int n, int x, int y, int dlugosc);

int main() {
    // Poziom rekurencji
    int poziom = 4;

    // Długość boku
    int dlugosc = 16;

    sierpinski(poziom, 0, 0, dlugosc);

    return 0;
}

void sierpinski(int n, int x, int y, int dlugosc) {
    // Jeśli poziom jest równy zero nie wykonujemy żadnej operacji
    if (n == 0) {
        return;
    }

    // Kod do rysowania trójkąta, zgodnie ze wzorem
    sierpinski(n - 1, x, y, dlugosc / 2);
    sierpinski(n - 1, x + dlugosc / 2, y, dlugosc / 2);
    sierpinski(n - 1, x + dlugosc / 4, y + dlugosc / 2, dlugosc / 2);
}