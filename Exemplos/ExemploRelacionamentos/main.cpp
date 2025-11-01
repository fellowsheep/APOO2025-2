#include "Mago.h"
#include "BolaDeFogo.h"

int main()
{
    Mago mago;

    BolaDeFogo *bola = new BolaDeFogo;

    mago.lancar(bola);

    mago.lancarBolaDeFogo();

    return 0;
}