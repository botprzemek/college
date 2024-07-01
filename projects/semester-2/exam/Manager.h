#ifndef MANAGER_H
#define MANAGER_H

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
