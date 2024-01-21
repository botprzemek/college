// Logger - Klasa wywołująca
//
// Plik zawiera klasę zawierającą metody wywołujące i zbierające
// zmienne wejściowe z konsoli od użytkownika.

#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>

using namespace std;

class Logger {
public:
    static void title(const string& title);
    static void message(const string& message);
    static int inputInt(const string& input);
    static string inputString(const string& input);
};

#endif
