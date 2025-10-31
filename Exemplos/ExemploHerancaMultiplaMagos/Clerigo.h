#ifndef CLERIGO_H
#define CLERIGO_H

#include "MagoBranco.h"
#include "MagoAmarelo.h"
// Derivada: Combina os dois papéis
// (Não muda nada aqui)
class Clerigo : public MagoBranco, public MagoAmarelo {
public:
    void bencaoSuprema() {
        std::cout << "[Clerigo] Bencao Suprema!" << std::endl;
        
        // SUCESSO! Não há mais ambiguidade.
        // O Clerigo sabe que existe APENAS UM nivelDeMagia.
        this->nivelDeMagia = 10; 
        
        // SUCESSO! Não há mais ambiguidade.
        // O Clerigo sabe que existe APENAS UM restaurarMana().
        this->restaurarMana();
    }
};

#endif