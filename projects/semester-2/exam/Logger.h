#ifndef LOGGER_H
#define LOGGER_H

struct Logger {
    void (*title)(const char*);
    void (*message)(const char*);
    int (*getInt)(const char*);
    char* (*getString)(const char*);
};

struct Logger* getLogger();

#endif
