#include <iostream>
#include <cmath>

// Klasa Kolo
class Kolo {
private:
    double promien;

public:
    Kolo(double promien) : promien(promien) {}

    double pole() const {
        return M_PI * promien * promien;
    }

    double obwod() const {
        return 2 * M_PI * promien;
    }
};

// Klasa Kwadrat
class Kwadrat {
private:
    double bok;

public:
    Kwadrat(double bok) : bok(bok) {}

    double pole() const {
        return bok * bok;
    }

    double obwod() const {
        return 4 * bok;
    }
};

// Klasa Prostokat
class Prostokat {
private:
    double dlugosc;
    double szerokosc;

public:
    Prostokat(double dlugosc, double szerokosc) : dlugosc(dlugosc), szerokosc(szerokosc) {}

    double pole() const {
        return dlugosc * szerokosc;
    }

    double obwod() const {
        return 2 * (dlugosc + szerokosc);
    }
};

int main() {
    Kolo k(5.0);
    Kwadrat kw(4.0);
    Prostokat p(6.0, 3.0);

    std::cout << "Pole kola: " << k.pole() << std::endl;
    std::cout << "Obwod kola: " << k.obwod() << std::endl;

    std::cout << "Pole kwadratu: " << kw.pole() << std::endl;
    std::cout << "Obwod kwadratu: " << kw.obwod() << std::endl;

    std::cout << "Pole prostokata: " << p.pole() << std::endl;
    std::cout << "Obwod prostokata: " << p.obwod() << std::endl;

    return 0;
}
