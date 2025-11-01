#ifndef MAGO_H
#define MAGO_H

#include "Magia.h"
#include "BolaDeFogo.h"

class Mago {
public:
    inline Mago() {}
    // Exemplo 1: Recebendo a magia como parâmetro
    void lancar(Magia* magia) {
        std::cout << "Mago prepara o feitiço..." << std::endl;
        magia->executar();
        //magia->queimar(); ERRO! Não pode porque aqui recebemos a bola de fogo como sua superclasse Magia por polimorfismo
    }
    
    // Exemplo 2: Instanciando a magia localmente
    void lancarBolaDeFogo() {
        BolaDeFogo bola; // Criada na pilha
        std::cout << "Mago cria uma bola de fogo..." << std::endl;
        bola.executar();
    } // 'bola' é destruída aqui
};

#endif