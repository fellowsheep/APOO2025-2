#include <iostream> //permite fazer escrita e leitura de dados usando as streams cin cout
#include "Notas.h"

int main()
{
    // Comando de saída
    std::cout << "Ola mundo!\n";

    int a, b, c;
    float d;
    // Comando de entrada 
    std::cin >> a >> b >> c >> d;

    std::cout << "A = " << a << "\nB = " << b;

    return 0;
}