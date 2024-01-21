// Player - Klasa obiektu (Gracza Koszykówki)
//
// Plik zawiera pola określające dane gracza i metody związane z dostępem
// do jego danych.

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

using namespace std;

class Player {
private:
    string firstName;
    string lastName;
    int number;
    int height;
    int position;

public:
    Player();
    Player(string newFirstName, string newLastName, int newNumber, int newHeight, int newPosition);

    string getFirstName();
    string getLastName();

    int getNumber();
    int getHeight();
    int getPosition();

    Player* setFirstName(string newFirstName);
    Player* setLastName(string newLastName);
    Player* setNumber(int newNumber);
    Player* setHeight(int newHeight);
    Player* setPosition(int newPosition);
};

#endif
