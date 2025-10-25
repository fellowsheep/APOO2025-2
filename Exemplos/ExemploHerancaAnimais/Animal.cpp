#include "Animal.h"

Animal::Animal(string nome)
{
    setlocale(LC_ALL, "");
    this->nome = nome;
}

Animal::~Animal()
{

}
