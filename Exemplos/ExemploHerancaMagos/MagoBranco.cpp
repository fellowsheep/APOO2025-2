#include "MagoBranco.h"

MagoBranco::MagoBranco(string nome, int idade, string escolaDeMagia) : Mago(nome,idade,escolaDeMagia)
{
    poderCura = 0;
    cout << "Mago Branco " << nome << " foi criado!" << endl;
}

void MagoBranco::lancarCura()
{
    cout << "Estou curando você!" << endl;
}
