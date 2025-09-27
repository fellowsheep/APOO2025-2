#include "MagoCSV.h"

int main()
{
    MagoCSV m;
    int nroMagos = 0;
    Mago *magos = m.deserialize("magos.csv", nroMagos);
    //-----
    for (int i=0; i<nroMagos; i++)
    {
        cout << "Mago " << i << ": " << magos[i].retornarNome() << ", " << magos[i].retornarIdade() << ", " << magos[i].retornarEscolaMagia() << endl;
    }

    // Cadastro rápido de um novo mago (poderia criar função)
    magos[nroMagos].alterarNome("A");
    magos[nroMagos].alterarIdade(10);
    magos[nroMagos].alterarEscolaMagia("B");
    nroMagos++;
    //--------
    m.serialize(magos,nroMagos);


    return 0;
}