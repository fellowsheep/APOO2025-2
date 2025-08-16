#include "Mago.h"

int main()
{
    Mago mago; // instanciando um objeto da classe mago.

    // Invocando os métodos 
    mago.andar();
    mago.falar("Ola mundo da OO!");
    mago.invocarMagia();
    getchar(); // Espera apertar uma tecla
    return 0;
}