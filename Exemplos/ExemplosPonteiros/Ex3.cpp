#include <iostream>
#include <ctime>
#include <clocale>

using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    srand(time(0));

    int *ponteiro = new int;
    *ponteiro = 100;

    cout << "A variável ponteiro armazena o endereço " << ponteiro << " para uma região da memória que armazena um int." << endl;
    cout << "O valor armazenado nessa região de memória é " << *ponteiro << endl;

    delete ponteiro; // desalocando a região de memória apontada por ponteiro
    cout << "Agora ponteiro possui o valor " << ponteiro << endl; //a região de memória antes alocada pode ser usada novamente em outro momento, porque ela foi liberada.

    cout << *ponteiro << endl; //mostrando que está desalocado

    ponteiro = new int[10]; //está alocando dinamicamente uma região em que ficarão 10 inteiros em sequencia.
                            //ponteiro quarda o endereço para onde está o primeiro elemento
    cout << "A variável ponteiro agora armazena o endereço " << ponteiro << " para uma região da memória que armazena 10 inteiros em sequencia." << endl;
    ponteiro[0] = 200;
    cout << ponteiro[0] << " = " << *ponteiro << endl;

    for(int i=0; i<10; i++)
    {
        ponteiro[i] = rand() % 10 + 1;
        cout << ponteiro[i] << " ";
    }
    cout << endl;
    cout << ponteiro[3] << endl;
    delete[] ponteiro; // Desaloca toda a região de memória apontada por ponteiro
    cout << ponteiro[3] << endl;

    return 0;
}