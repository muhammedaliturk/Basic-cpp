#ifndef STR_H
#define STR_H

#include <cstring>
#include <iostream>

class Str {
public:
    Str();
    Str(const char* str);
    Str(const Str& other);
    ~Str();
    Str& operator=(const Str& other);
    Str& operator++();
    char& operator[](int index);
    void print() const;
private:
    char* data;
    int size;
};

#endif  
