int zagniezdzona(int liczba);

int main() {
    // Liczba, która zostanie użyta funkcji zagnieżdżonej
    int liczba = 5;

    zagniezdzona(liczba);

    return 0;
}

int zagniezdzona(int liczba) {
    if (liczba <= 1) {
        return liczba;
    }

    return zagniezdzona(liczba - 1) + zagniezdzona(liczba - 1);
}