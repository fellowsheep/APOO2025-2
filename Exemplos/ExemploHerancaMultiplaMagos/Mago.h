#ifndef MAGO_H
#define MAGO_H

#include <iostream>
#include <string>

// A classe base no topo do diamante (não muda)
class Mago {
public:
    int nivelDeMagia; 

    Mago() : nivelDeMagia(1) {}

    void restaurarMana() {
        std::cout << "Restaurando Mana! Nivel atual: " << nivelDeMagia << std::endl;
    }
};

#endif