#include "Str.h"
using namespace std;
Str::Str(){
    data = nullptr; size=0;
}

Str::Str(const char* str){
    size=static_cast<int>(strlen(str));
    data = new char[size + 1];
    strcpy_s(data, size + 1, str);
}


Str::Str(const Str& other){
    size=other.size;
    data = new char[size + 1];
    strcpy_s(data, size + 1, other.data);
}


Str::~Str() {
    delete[] data;
}


Str& Str::operator=(const Str& other) {
    if (this != &other) {
        delete[] data;

        size = other.size;
        data = new char[size + 1];
        strcpy_s(data, size + 1, other.data);
    }
    return *this;
}


Str& Str::operator++() {
    for (int i = 0; i < size; ++i) {
        ++data[i];
    }
    return *this;
}


char& Str::operator[](int index) {
    if (index >= 0 && index < size) {
        return data[index];
    }
    else {
        throw out_of_range("Index out of range");
    }
}


void Str::print() const {
    if (data != nullptr) {
        cout << data << endl;
    }
    else {
        cout << "(empty)" << endl;
    }
}
