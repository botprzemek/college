#include <iostream>

class Statistics {
    private:
        int health;
        int strength;

    public:
        Statistics() {
            this->health = 20;
            this->strength = 2;
        };
        Statistics setHealth(int newHealth) {
            this->health = newHealth;
        };
        void setStrength(int newStrength) {
            this->strength = newStrength;
        };
        int getHealth() {
            return this->health;
        };
        int getStrength() {
            return this->strength;
        };
        int getDamage() {
            return (rand() % this->strength) + 1;
        }
};

class Player {
    private:
        char* nickname;
        Statistics statistics;

    public:
        Player(char* nickname) {
            this->nickname = nickname;
            this->statistics = Statistics();
        };
        char* getNickname() {
            return this->nickname;
        };
        Statistics* getStatistics() {
            return &(this->statistics);
        };
        void dealDamage(Player* target) {
            int healthLeft = (*(*target).getStatistics()).getHealth() - (*this->getStatistics()).getDamage();

            (*(*target).getStatistics()).setHealth(healthLeft);
        };
};

class Logger {
    public:
        void playerHealth(Player* player) {
            std::cout << (*player).getNickname() << "'s health: " <<  (*(*player).getStatistics()).getHealth() << std::endl;
        };
};

class PlayerManager {
    private:
        std::vector<Player*> players;

    public:
        PlayerManager() {
            players.reserve(1);
        };
        void add(Player* player) {
            players.push_back(&(*player));
            players.reserve(players.size() + 1);
        };
        Player* get(int id) {
            return &(*players.at(id));
        };
};

int main() {
    srand(time(NULL));

    PlayerManager playerManager;
    Logger logger;

    Player player1((char*) "Foo");
    Player player2((char*) "Bar");

    playerManager.add(&player1);
    playerManager.add(&player2);

    logger.playerHealth(&player2);

    player1.dealDamage(&player2);

    logger.playerHealth(&player2);

    return 0;
}