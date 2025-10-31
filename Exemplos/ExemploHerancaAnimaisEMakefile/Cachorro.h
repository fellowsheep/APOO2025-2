#ifndef CACHORRO_H
#define CACHORRO_H

#include "Animal.h"

class Cachorro : public Animal
{
    public:
    // Apenas passa o gerenciador para a classe base (Animal)
    Cachorro(string nome, GerenciadorSom& gerenciador);
    virtual void fazerSom();
};

#endif