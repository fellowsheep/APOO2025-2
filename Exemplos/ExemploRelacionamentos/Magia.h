#ifndef MAGIA_H
#define MAGIA_H

#include<iostream>
#include<string>

using namespace std;

class Magia {
public:
    inline Magia() {}
    virtual void executar() = 0; // Abstrato
};

#endif