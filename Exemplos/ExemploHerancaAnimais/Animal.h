#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>
#include <clocale>

#define MINIAUDIO_IMPLEMENTATION
#include "miniaudio.h"

using namespace std;

class Animal
{
    public:
        Animal(string nome);
        virtual void fazerSom() = 0; // Método virtual que torna Animal uma classe abstrata
        ~Animal();
    protected:
        string nome;
       
};

#endif