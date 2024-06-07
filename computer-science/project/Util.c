#include "Util.h"
#include "Constants.h"

char* getPositionName(int index) {
    return (index > 0 && index - 1 < 4) ? Constants::POSITIONS.at(index) : Constants::POSITIONS.at(0);
}

struct Util util = {
    .getPositionName =  getPositionName,
};

struct Util* getUtil() {
    return &util;
}