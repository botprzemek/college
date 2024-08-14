int nested(int number);

int main() {
    int number = 5;

    nested(number);

    return 0;
}

int nested(int number) {
    if (number <= 1) {
        return number;
    }

    return nested(--number) + nested(--number);
}
