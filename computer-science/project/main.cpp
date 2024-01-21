// Main - Główny
//
// Zawiera podstawowe menu oraz inicjalizuje klasę zarządzającą danymi,
// Po skompilowaniu i uruchomieniu pliku wyświetlone zostaną podstawowe opcje.

#include <iostream>

#include "Constants.h"
#include "Logger.h"
#include "Manager.h"

using namespace std;

int main() {
    Manager manager;

    while (true) {
        Logger::title("Basketball Player Manager");

        string message;
        for (int i = 0; i < Constants::OPTIONS.size(); i++) {
            Logger::message(to_string(i + 1) + ". " + Constants::OPTIONS.at(i));
        }

        int option = Logger::inputInt("option: ");

        switch (option) {
            case 1:
                manager.create();
                break;
            case 2:
                manager.edit();
                break;
            case 3:
                manager.view();
                break;
            case 4:
                manager.save();
                return 0;
            default:
                break;
        }
    }
}