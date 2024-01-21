#include <fstream>

#include "Constants.h"
#include "Logger.h"
#include "Manager.h"
#include "Util.h"

vector<Player> players;

Manager::Manager() {
    load();
}

void Manager::create() {
    Logger::title("Creating player");

    string firstName = Logger::inputString("first name: ");
    string lastName = Logger::inputString("last name: ");

    int number = Logger::inputInt("number: ");
    int height = Logger::inputInt("height: ");

    for (int i = 0; i < Constants::POSITIONS.size(); i++) {
        Logger::message(to_string(i + 1) + ". " + Constants::POSITIONS.at(i));
    };
    int option = Logger::inputInt("position: ");

    int position = (option > 0 && option < Constants::POSITIONS.size() + 1) ? option - 1 : 0;

    Player player(firstName, lastName, number, height, position);

    players.push_back(player);

    save();
};
bool Manager::edit() {
    view();

    int index = Logger::inputInt("player index: ") - 1;

    for (int i = 0; i < Constants::FIELDS.size(); i++) {
        Logger::message(to_string(i + 1) + ". " + Constants::FIELDS.at(i));
    };

    int field = Logger::inputInt("field: ") - 1;

    Player player = players.at(index);

    switch (field) {
        case 0:
            player.setFirstName(Logger::inputString("new first name: "));
            break;
        case 1:
            player.setLastName(Logger::inputString("new last name: "));
            break;
        case 2:
            player.setNumber(Logger::inputInt("new number: "));
            break;
        case 3:
            player.setHeight(Logger::inputInt("new height: "));
            break;
        case 4:
            for (int i = 0; i < Constants::POSITIONS.size(); i++) {
                Logger::message(to_string(i + 1) + ". " + Constants::POSITIONS.at(i));
            };

            int option = Logger::inputInt("position: ");

            player.setPosition((option > 0 && option < Constants::POSITIONS.size() + 1) ? option - 1 : 0);
            break;
    }

    players.at(index) = player;



    save();

    return true;
}

void Manager::view() {
    load();

    string message;
    for (int i = 0; i < players.size(); i++) {
        message += to_string(i + 1) + ". " + players.at(i).getFirstName() + " " + players.at(i).getLastName() + " #" + to_string(players.at(i).getNumber()) + " (" + to_string(players.at(i).getHeight()) + "cm - " + Util::getPositionName(players.at(i).getPosition()) + ")\n";
    }

    Logger::message(message);
}

void Manager::save() {
    ofstream file("players.txt");

    if (!file.is_open()) return;

    Logger::title("Saving players");

    for (Player player : players) {
        file << player.getFirstName() << ";" <<
             player.getLastName() << ";" <<
             player.getNumber() << ";" <<
             player.getHeight() << ";" <<
             player.getPosition() << ";" << endl;
    }

    file.close();
}

void Manager::load() {
    ifstream file("players.txt");

    if (!file.is_open()) return;

    Logger::title("Loading players");

    players.clear();

    string line;

    while (getline(file, line)) {
        vector<string> data;

        data.emplace_back("");
        for (char character : line) {
            if (character == ';') {
                data.emplace_back("");
                continue;
            }
            data.back() = data.back() + character;
        }

        Player player(
                data.at(0),
                data.at(1),
                stoi(data.at(2)),
                stoi(data.at(3)),
                stoi(data.at(4))
                );

        players.push_back(player);
    }

    file.close();
}