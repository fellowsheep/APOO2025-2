#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>

using namespace std;

// Forward Declaration:
// Apenas "avisamos" ao compilador que essa classe existe.
// Assim, evitamos incluir o .h inteiro, melhorando a compilação
// e o desacoplamento.
class GerenciadorSom; 

class Animal
{
    public:
        // Agora recebe o gerenciador
        Animal(string nome, GerenciadorSom& gerenciador);
        virtual void fazerSom() = 0;
        virtual ~Animal(); // É boa prática ter um destrutor virtual na classe base

    protected:
        string nome;
        GerenciadorSom& gerenciador; // Armazena uma REFERÊNCIA
       
};

#endif