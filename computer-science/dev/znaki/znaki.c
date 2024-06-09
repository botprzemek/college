#include <ctype.h>
#include <stdio.h>

#define MAX_LEN 128

int str_len(char s[]);

int lwr_str_cnt(char s[]);

int upr_str_cnt(char s[]);

int dgt_str_cnt(char s[]);

int nalpha_str_cnt(char s[]);

int chr_str_cnt(char c, char s[]);

int chr_str_pos(char c, char s[]);

int chr_str_rpos(char c, char s[]);

void str_rev(char s[]);

int main() {
    char line[MAX_LEN];
    char znak;
    int pos;

    printf("\n\nWpisz linie tekstu: ");
    gets(line);

    printf("\nLiczba znakow : %d", str_len(line));
    printf("\nLiczba malych liter : %d", lwr_str_cnt(line));
    printf("\nLiczba duzych liter : %d", upr_str_cnt(line));
    printf("\nLiczba cyfr : %d", dgt_str_cnt(line));
    printf("\nLiczba innych znakow : %d", nalpha_str_cnt(line));

    printf("\n\nPodaj pojedynczy znak: ");
    znak = getchar();
    fflush(stdin);

    printf("\nLiczba wystapien znaku %c : %d", znak, chr_str_cnt(znak, line));
    if ((pos = chr_str_pos(znak, line)) != -1)
        printf("\nPierwsze wystapienie znaku %c od poczatku : %d", znak, pos + 1);
    else
        printf("\nZnak %c nie zostal znaleziony", znak);

    if ((pos = chr_str_rpos(znak, line)) != -1)
        printf("\nPierwsze wystapienie znaku %c od konca : %d", znak, pos + 1);
    else
        printf("\nZnak %c nie zostal znaleziony", znak);

    printf("\n\nNapis oryginalny : %s", line);
    str_rev(line);
    printf("\nNapis odwrocony : %s", line);

    (void) getchar();
    return 0;
}


int str_len(char s[]) {
    int dlugosc = 0;

    while (s[dlugosc] != '\0') {
        dlugosc++;
    }

    return dlugosc;
}

int lwr_str_cnt(char s[]) {
    int ilosc = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (islower(s[i])) {
            ilosc++;
        }
    }

    return ilosc;
}

int upr_str_cnt(char s[]) {
    int ilosc = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (isupper(s[i])) {
            ilosc++;
        }
    }

    return ilosc;
}

int dgt_str_cnt(char s[]) {
    int ilosc = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (isdigit(s[i])) {
            ilosc++;
        }
    }

    return ilosc;
}

int nalpha_str_cnt(char s[]) {
    int ilosc = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (isalnum(s[i])) {
            ilosc++;
        }
    }

    return ilosc;
}

int chr_str_cnt(char c, char s[]) {
    int ilosc = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == c) {
            ilosc++;
        }
    }

    return ilosc;
}

int chr_str_pos(char c, char s[]) {
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == c) {
            return i;
        }
    }

    return -1;
}

int chr_str_rpos(char c, char s[]) {
    int pozycja = -1;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == c) {
            pozycja = i;
        }
    }

    return pozycja;
}

void str_rev(char s[]) {
    int dlugosc = str_len(s);

    for (int i = 0; i < dlugosc / 2; i++) {
        char tmp = s[i];
        s[i] = s[dlugosc - 1 - i];
        s[dlugosc - 1 - i] = tmp;
    }
}
