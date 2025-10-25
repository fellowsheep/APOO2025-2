#ifndef FIRE_POKEMON_H
#define FIRE_POKEMON_H

#include "Pokemon.h"

class FirePokemon : public Pokemon
{
    public:
    FirePokemon(string name, int index);
    virtual void evolve() = 0;
    void burnUp(); //apenas o pokemon tipo fogo tem

};

#endif