#include "Util.h"
#include "Constants.h"

string Util::getPositionName(int index) {
    return (index > 0 && index - 1 < 4) ? Constants::POSITIONS.at(index) : Constants::POSITIONS.at(0);
}