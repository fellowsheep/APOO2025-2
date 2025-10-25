#include "Charmander.h"

Charmander::Charmander(string name, int index): FirePokemon(name,index)
{
    cout << "Um pokemon " << name << " foi criado!" << endl;
}

void Charmander::evolve()
{
    string previousName = name;

    if (statusEvolution == 0)
    {
        name = "Charmeleon";
        statusEvolution = 1;
        index++;
    }
    else if (statusEvolution == 1)
    {
        name = "Charizard";
        statusEvolution = 2;
        index++;
    }
    else 
    {
        cout << "Atingiu o máximo da evolucao da sua espécie!" << endl;
        return;
    }
    cout << previousName << " evoluiu e agora é um " << name << endl;
}
