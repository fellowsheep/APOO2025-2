#ifndef GERENCIADORDEESOM_H
#define GERENCIADORDEESOM_H

#include <string>
#include "miniaudio.h" // Só este arquivo conhece a miniaudio

using namespace std;

class GerenciadorSom
{
public:
    GerenciadorSom();  // Construtor inicializa a engine
    ~GerenciadorSom(); // Destrutor libera a engine

    void tocarSom(string nomeArquivo);

private:
    ma_engine engine;
    bool inicializadoComSucesso;
};

#endif