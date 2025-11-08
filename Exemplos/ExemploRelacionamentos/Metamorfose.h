#ifndef METAMORFOSE_H
#define METAMORFOSE_H

#include "Magia.h"

class Metamorfose : public Magia {
public:
    inline Metamorfose() {}
    // Métdo virtual de Magia sendo implementado por Metamorfose
    void executar() override {
        std::cout << "Morfaar!" << std::endl;
    }
   << endl; }
};

#endif