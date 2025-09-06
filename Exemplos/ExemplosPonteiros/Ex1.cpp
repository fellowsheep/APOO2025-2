#include <iostream>
#include <clocale>

using namespace std;

int main()
{
    setlocale(LC_ALL, "");

    int numero = 100;
    int *ponteiro = &numero;
    int *ptr = NULL; // inicializando um ponteiro sem endereço nenhum (pode usar 0)


    cout << "Conteúdo da var número: " << numero << endl;
    cout << "Endereço da var número: " << &numero << endl;

    cout << "Conteúdo da var ponteiro: " << ponteiro << endl;
    cout << "Endereço da var ponteiro: " << &ponteiro << endl;
    cout << "Conteúdo da var referenciada pelo ponteiro:" << *ponteiro << endl; //desreferenciação
    *ponteiro = 200;
    cout << "Conteúdo da var número: " << numero << endl;
    // cout << *numero << endl; Erro! Não tem como desreferenciar um não ponteiro!
    // cout << ": " << *ptr << endl; Erro! Não tem como desreferenciar um ponteiro que está sem endereço
    ptr = ponteiro;
    if (ptr == NULL) //valida se o ponteiro está armazenando um endereço
    {
        cout << "Não está referenciando ninguém!!" << endl;
    }
    else 
    {
        cout << "Conteúdo da var referenciada por ptr: " << *ptr << endl;
    }
    return 0;
}