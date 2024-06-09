#include <iostream>

using namespace std;

class Samochod {
private:
    int vMax;
    double paliwoWZbiorniku;
    double zuzycieNa100km;

public:
    Samochod() : vMax(120), paliwoWZbiorniku(50.0), zuzycieNa100km(8.0) {}

    Samochod(int vMax, double paliwoWZbiorniku, double zuzycieNa100km) : vMax(vMax), paliwoWZbiorniku(paliwoWZbiorniku),
                                                                         zuzycieNa100km(zuzycieNa100km) {}

    int getVMax() const {
        return vMax;
    }

    double getPaliwoWZbiorniku() const { return paliwoWZbiorniku; }

    double getZuzycieNa100km() const { return zuzycieNa100km; }

    void setVMax(int vMax) { this->vMax = vMax; }

    void setPaliwoWZbiorniku(double paliwoWZbiorniku) { this->paliwoWZbiorniku = paliwoWZbiorniku; }

    void setZuzycieNa100km(double zuzycieNa100km) { this->zuzycieNa100km = zuzycieNa100km; }

    double zasieg() const {
        return (paliwoWZbiorniku / zuzycieNa100km) * 100.0;
    }

    double czasDojazdu(double dystans) const {
        double sredniaPredkosc = 0.75 * vMax;
        return dystans / sredniaPredkosc;
    }

    void zatankuj(double ilePaliwaZatankowano) {
        paliwoWZbiorniku += ilePaliwaZatankowano;
    }

    void trasa(double liczbaKilometrów) {
        double zuzytePaliwo = (liczbaKilometrów / 100.0) * zuzycieNa100km;
        paliwoWZbiorniku -= zuzytePaliwo;
    }

    void uzyskajAtrybuty() {
        cout << "[ vMax    : " << this->getVMax() << "   ]" << endl;
        cout << "[ Paliwo  : " << this->getPaliwoWZbiorniku() << "L   ]" << endl;
        cout << "[ Zuzycie : " << this->getZuzycieNa100km() << "     ]" << endl;
        cout << "[ Zasieg  : " << this->zasieg() << "KM ]" << endl << endl;
    }
};

int main() {
    Samochod samochod1;

    cout << "Samochod 1" << endl;
    samochod1.uzyskajAtrybuty();

    Samochod samochod2(180, 40.0, 6.5);

    cout << "Samochod 2" << endl;
    samochod1.uzyskajAtrybuty();

    cout << "Czas dojazdu s2 na 150 km: " << samochod1.czasDojazdu(150.0) << " h" << endl;

    samochod2.zatankuj(10.0);
    cout << "Paliwo Samochodu nr 2 po tankowaniu: " << samochod2.getPaliwoWZbiorniku() << " l" << endl;

    samochod2.trasa(200.0);
    cout << "Paliwo Samochodu nr 2 po trasie 200 km: " << samochod2.getPaliwoWZbiorniku() << " l" << endl;

    return 0;
}
