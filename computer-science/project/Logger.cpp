#include "Logger.h"
#include <iostream>

using namespace std;

void Logger::title(const string& title) {
    cout << "..." << title << "..." << endl;
}

void Logger::message(const string& message) {
    cout << message << endl;
}

int Logger::inputInt(const string& input) {
    int value;
    cout << "Enter " + input;
    cin >> value;
    cout << endl;
    return value;
}

string Logger::inputString(const string& input) {
    string value;
    cout << "Enter " + input;
    cin >> value;
    return value;
}
