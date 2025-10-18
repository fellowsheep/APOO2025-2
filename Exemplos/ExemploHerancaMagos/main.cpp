#include "MagoBranco.h"

int main()
{
    MagoBranco magoBranco("Gandalf",2019,"Istari");

    magoBranco.falar("Olá!"); //invocando método da superclasse
    magoBranco.lancarCura();


    return 0;
}