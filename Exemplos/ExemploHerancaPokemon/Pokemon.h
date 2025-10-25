#ifndef POKEMON_H
#define POKEMON_H

#include <string>
#include <iostream>

using namespace std;

class Pokemon
{
    public:
        Pokemon(string name, int index);
        virtual void evolve() = 0;
    protected:
        string name;
        int index;
        int statusEvolution;

};

#endif