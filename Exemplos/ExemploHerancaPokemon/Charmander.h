#ifndef CHARMANDER_H
#define CHARMANDER_H

#include "FirePokemon.h"

class Charmander : public FirePokemon
{
    public:
        Charmander(string name, int index);
        virtual void evolve();
    
};

#endif