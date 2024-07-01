#include <iostream>
#include <cmath>

using namespace std;

class Kolo {
private:
    double promien;

public:
    explicit Kolo(double promien) : promien(promien) {}

    double pole() const {
        return M_PI * promien * promien;
    }

    double obwod() const {
        return 2 * M_PI * promien;
    }
};

class Prostokat {
protected:
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

class Kwadrat : public Prostokat {
public:
    explicit Kwadrat(double bok): Prostokat(bok, bok) {}
};

int main() {
    cout << "Figury" << endl << endl;


    cout << "Kolo: " << endl << endl;

    Kolo kolo(5.0);

    cout << "Pole: " << kolo.pole() << endl;
    cout << "Obwod: " << kolo.obwod() << endl << endl;

    cout << "Prostokat: " << endl << endl;

    Prostokat prostokat(6.0, 3.0);

    cout << "Pole: " << prostokat.pole() << endl;
    cout << "Obwod: " << prostokat.obwod() << endl << endl;

    cout << "Kwadrat: " << endl << endl;

    Kwadrat kwadrat(4.0);

    cout << "Pole: " << kwadrat.pole() << endl;
    cout << "Obwod: " << kwadrat.obwod() << endl << endl;

    return 0;
}