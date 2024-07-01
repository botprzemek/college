#include <stdlib.h>

#include "Constant.h"
#include "Constants.h"

struct Constant* createConstant() {
    struct Constants constants = {
        .length = 0,
    };
}

struct Constant* getConstants() {
   constants = (struct Constant**) malloc(sizeof(struct Constant*));

   struct Constant* fields = getConstant();
   struct Constant* options = getConstant();
   struct Constant* positions = getConstant();

   fields->addWord(fields, "First name");
   options->addWord(options, "Create player");
   positions->addWord(options, "Point Guard");

   constants

   return &constants;
}

void clearConstants() {
    for (int i = 0; i < constants)
    free(constants);
};

//    const vector<string> FIELDS = { "First name", "Last name", "Number", "Height", "Position" };
//    const vector<string> OPTIONS = { "Create Player", "Edit Player", "View Players", "Exit" };
//    const vector<string> POSITIONS = { "Point Guard", "Shooting Guard", "Small Forward", "Power Forward", "Center" };
//}