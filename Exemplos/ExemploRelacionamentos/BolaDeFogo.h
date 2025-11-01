#ifndef BOLA_DE_FOGO_H
#define BOLA_DE_FOGO_H

#include "Magia.h"

class BolaDeFogo : public Magia {
public:
    inline BolaDeFogo() {}
    // Métdo abstrato de Magia sendo implementado por Bola de Fogo
    void executar() override {
        std::cout << "Bola de Fogo explode!" << std::endl;
    }
    // Método especializado da Bola de Fogo
    inline void queimar() { cout << "Bola de Fogo queimando!!!" << endl; }
};

#endif