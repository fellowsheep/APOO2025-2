#ifndef MAGO_BRANCO_H
#define MAGO_BRANCO_H

#include "Mago.h"

class MagoBranco: public Mago {
public:
    MagoBranco(string nome, int idade, string escolaDeMagia);
    void lancarCura();

protected:
    int poderCura;

};

#endif