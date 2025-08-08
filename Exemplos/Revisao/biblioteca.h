#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <string>

struct Pessoa {
    std::string nome;
    int idade;
};

void mostrarPessoa(const Pessoa& p);

#endif
