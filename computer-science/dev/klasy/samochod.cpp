#include <iostream>

class Samochod {
private:
    int vMax;
    double paliwoWZbiorniku;
    double zuzycieNa100km;

public:
    // Konstruktor bez parametrów
    Samochod() : vMax(120), paliwoWZbiorniku(50.0), zuzycieNa100km(8.0) {}

    // Konstruktor z trzema parametrami
    Samochod(int vMax, double paliwoWZbiorniku, double zuzycieNa100km)
            : vMax(vMax), paliwoWZbiorniku(paliwoWZbiorniku), zuzycieNa100km(zuzycieNa100km) {}

    // Metody dostępowe
    int getVMax() const { return vMax; }
    double getPaliwoWZbiorniku() const { return paliwoWZbiorniku; }
    double getZuzycieNa100km() const { return zuzycieNa100km; }

    void setVMax(int vMax) { this->vMax = vMax; }
    void setPaliwoWZbiorniku(double paliwoWZbiorniku) { this->paliwoWZbiorniku = paliwoWZbiorniku; }
    void setZuzycieNa100km(double zuzycieNa100km) { this->zuzycieNa100km = zuzycieNa100km; }

    // Oblicza ile można przejechać na paliwie w zbiorniku
    double zasieg() const {
        return (paliwoWZbiorniku / zuzycieNa100km) * 100.0;
    }

    // Oblicza czas dojazdu zakładając średnią prędkość równą 3/4 vMax
    double czasDojazdu(double dystans) const {
        double sredniaPredkosc = 0.75 * vMax;
        return dystans / sredniaPredkosc;
    }

    // Zwiększa liczbę paliwa w zbiorniku
    void zatankuj(double ilePaliwaZatankowano) {
        paliwoWZbiorniku += ilePaliwaZatankowano;
    }

    // Zmniejsza liczbę paliwa w zbiorniku
    void trasa(double liczbaKilometrów) {
        double zuzytePaliwo = (liczbaKilometrów / 100.0) * zuzycieNa100km;
        paliwoWZbiorniku -= zuzytePaliwo;
    }
};

int main() {
    Samochod s1;
    Samochod s2(180, 40.0, 6.5);

    std::cout << "Zasieg s1: " << s1.zasieg() << " km" << std::endl;
    std::cout << "Czas dojazdu s2 na 150 km: " << s2.czasDojazdu(150.0) << " h" << std::endl;

    s2.zatankuj(10.0);
    std::cout << "Paliwo w zbiorniku s2 po tankowaniu: " << s2.getPaliwoWZbiorniku() << " l" << std::endl;

    s2.trasa(200.0);
    std::cout << "Paliwo w zbiorniku s2 po trasie 200 km: " << s2.getPaliwoWZbiorniku() << " l" << std::endl;

    return 0;
}
