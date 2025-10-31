#include "Cachorro.h"
#include "GerenciadorSom.h"

Cachorro::Cachorro(string nome, GerenciadorSom& gerenciador): Animal(nome,gerenciador)
{
    cout << "Cachorro " << this->nome << " foi criado!" << endl;
}

void Cachorro::fazerSom()
{
    cout << "Au au!!" << endl;
    
    // Delega a responsabilidade!
    // O Cachorro não sabe como, ele apenas pede.
    gerenciador.tocarSom("Bluthund_jault.mp3");
}

