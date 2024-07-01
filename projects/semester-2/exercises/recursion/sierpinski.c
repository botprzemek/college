void sierpinski(int level, int x, int y, int length);

int main() {
    int level = 4;
    int length = 16;

    sierpinski(level, 0, 0, length);

    return 0;
}

void sierpinski(int level, int x, int y, int length) {
    if (level == 0) {
        return;
    }

    sierpinski(level - 1, x, y, length / 2);
    sierpinski(level - 1, x + length / 2, y, length / 2);
    sierpinski(level - 1, x + length / 4, y + length / 2, length / 2);
}