#ifndef MAGO_BRANCO_H
#define MAGO_BRANCO_H

#include "Mago.h"

// Base 1: Focada em Proteção
// HERDA VIRTUALMENTE DE MAGO
class MagoBranco : public virtual Mago {
public:
    void escudoDeLuz() {
        std::cout << "[MagoBranco] Cria Escudo de Luz!" << std::endl;
    }
};
#endif