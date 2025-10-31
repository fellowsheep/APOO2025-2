#ifndef MAGO_AMARELO_H
#define MAGO_AMARELO_H

#include "Mago.h"
// Base 2: Focada em Cura
// HERDA VIRTUALMENTE DE MAGO
class MagoAmarelo : public virtual Mago {
public:
    void curarAliado(std::string alvo) {
        std::cout << "[MagoAmarelo] Cura [" << alvo << "]." << std::endl;
    }
};

#endif