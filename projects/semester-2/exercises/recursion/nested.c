int nested(int number);

int main() {
    int number = 5;

    nested(number);

    return 0;
}

int zagniezdzona(int number) {
    if (number <= 1) {
        return number;
    }

    return nested(--number) + nested(--number);
}