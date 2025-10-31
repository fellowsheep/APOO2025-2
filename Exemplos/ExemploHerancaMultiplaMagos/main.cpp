#include "Clerigo.h"

int main() {
    Clerigo sacerdote;
    
    // SUCESSO! O compilador não tem mais dúvidas.
    // Todas as chamadas apontam para a ÚNICA cópia do Mago.
    sacerdote.restaurarMana(); 

    sacerdote.escudoDeLuz();
    sacerdote.curarAliado("Guerreiro");
    
    // Chama o método que agora também funciona
    sacerdote.bencaoSuprema();
    
    return 0;
}