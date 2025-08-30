#include "Program.h"

char Program::showMenu()
{
    char option;
    cout << "============= MENU DE OPCOES ==============" << endl;
    cout << " 1 - Abrir uma caixa" << endl;
    cout << " 2 - Consultar itens" << endl;
    cout << " 3 - Sair do Programa" << endl;
    cout << " Digite uma opcao: ";
    cin >> option;
    return option;
}

void Program::openBox()
{
    int number = rand() % 100 + 1; //sorteia um valor de 1 a 100
    if(number <=80)
    {
        cout << "Item comum debloqueado!" << endl;
        nCommons++;
    }
    else if (number <=99)
    {
        cout << "Item raro desbloqueado!" << endl;
        nRares++;
    }
    else
    {
        cout << "Item lendário desbloqueado!" << endl;
        nLengendaries++;
    }
}

void Program::showInfo()
{
    cout << "INVENTARIO" << endl;
    cout << "Nro de itens comuns: " << nCommons << endl;
    cout << "Nro de itens raros: " << nRares << endl;
    cout << "Nro de itens lendarios: " << nLengendaries << endl;
}

Program::Program()
{
    initialize();
}

Program::~Program()
{
}

void Program::initialize()
{
    srand(time(0)); //usando a hora do sistema como semente para randomização
    nCommons = 0;
    nRares = 0;
    nLengendaries = 0;
}

void Program::run()
{
    char option;
    do {
    
    option = showMenu();
    switch(option)
    {
        case '1': // abrir caixa
             cout << "Abrindo uma caixa!" << endl;
             openBox();
             break;
        case '2': // consultar itens
             cout << "Consultando itens..." << endl;
             showInfo();
             break;
        case '3': // sair do programa
            cout << "Saindo do programa!" << endl;
            break;
        default: // opcao invalida
            cout << "Opcao invalida!" << endl;
    }


    }while(option != '3');

}

void Program::finish()
{
}
