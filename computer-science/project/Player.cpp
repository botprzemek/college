#include "Player.h"

Player::Player() {}

Player::Player(string newFirstName, string newLastName, int newNumber, int newHeight, int newPosition) {
    this->firstName = std::move(newFirstName);
    this->lastName = std::move(newLastName);
    this->number = newNumber;
    this->height = newHeight;
    this->position = newPosition;
}

string Player::getFirstName() {
    return this->firstName;
}

string Player::getLastName() {
    return this->lastName;
}

int Player::getNumber() {
    return this->number;
}

int Player::getHeight() {
    return this->height;
}

int Player::getPosition() {
    return this->position;
}

Player* Player::setFirstName(string newFirstName) {
    this->firstName = std::move(newFirstName);
    return this;
}

Player* Player::setLastName(string newLastName) {
    this->lastName = std::move(newLastName);
    return this;
}

Player* Player::setNumber(int newNumber) {
    this->number = newNumber;
    return this;
}

Player* Player::setHeight(int newHeight) {
    this->height = newHeight;
    return this;
}

Player* Player::setPosition(int newPosition) {
    this->position = newPosition;
    return this;
}