#include "FirePokemon.h"

FirePokemon::FirePokemon(string name, int index) : Pokemon(name, index)
{
    cout << this->name << " é um pokemon tipo fogo" << endl;
}

void FirePokemon::burnUp()
{
    cout << "Burning up!!!!!!!!" << endl;
}
