#include "biblioteca.h"
#include <iostream>

void mostrarPessoa(const Pessoa& p) {
    std::cout << p.nome << " tem " << p.idade << " anos.\n";
}