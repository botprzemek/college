// Constants - Zmienne stałe
//
// Plik zawiera zmienne określające opcje i pola
// odpowiednich klas użytych w projekcie.

#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <iostream>

using namespace std;

namespace Constants {
    const vector<string> FIELDS = { "First name", "Last name", "Number", "Height", "Position" };
    const vector<string> OPTIONS = { "Create Player", "Edit Player", "View Players", "Exit" };
    const vector<string> POSITIONS = { "Point Guard", "Shooting Guard", "Small Forward", "Power Forward", "Center" };
}

#endif