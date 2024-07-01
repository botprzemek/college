#ifndef UTIL_H
#define UTIL_H

struct Util {
    char* (*getPositionName)(int);
};

struct Util* getUtil();

#endif
