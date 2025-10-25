#ifndef CACHORRO_H
#define CACHORRO_H

#include "Animal.h"

class Cachorro : public Animal
{
    public:
    Cachorro(string nome,ma_engine *engine);
    virtual void fazerSom();
    protected:
    ma_engine *engine;

};

#endif