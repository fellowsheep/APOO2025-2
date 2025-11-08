#include "Mago.h"
#include "BolaDeFogo.h"
#include "Metamorfose.h"

int main()
{
    Mago mago;

    BolaDeFogo *bola = new BolaDeFogo;

    mago.lancar(bola);

    Metamorfose *metamorfose = new Metamorfose;

    mago.lancar(metamorfose)

    mago.lancarBolaDeFogo();

    Magia *magias[3];
    magias[0] = bola;
    magias[1] = metamorfose;
    magias[2] = nullptr;

    //magias[0]->queimar(); //ERRO!! 
    BolaDeFogo bola2 = (BolaDeFogo *) magias[0]; //cast simples
    bola2->queimar();

    for (i=0; i < 3; i++)
    {
        if (magias[i]!=nullptr)
        {
            magias[i]->executar();
        }
    }



    return 0;
}