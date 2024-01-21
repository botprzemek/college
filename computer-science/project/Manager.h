// Manager - Klasa zarządzająca
//
// Plik zawiera wektor klasy Player zawierający instacje stworzonych wcześniej graczy.
// Zawiera również metody na manipulację i wyświetlanie danych wektora.

#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>

#include "Player.h"

using namespace std;

class Manager {
private:
    vector<Player> players;

public:
    Manager();

    void create();
    void view();
    void save();
    void load();

    bool edit();
};

#endif
