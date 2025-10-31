#include "Animal.h"
// O .cpp precisa do include completo para inicializar o construtor
#include "GerenciadorSom.h"

Animal::Animal(string nome, GerenciadorSom& gerenciador): gerenciador(gerenciador) // <-- Inicialização da referência obrigatória aqui!
{
    //this->nome = nome;
}

Animal::~Animal()
{
    //Encerrar e desalocar tudo o que é de cachorro aqui
}
