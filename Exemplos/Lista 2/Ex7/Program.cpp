#include "Program.h"

char Program::showMenu()
{
    char option;
    cout << "============= MENU DE OPCOES ==============" << endl;
    cout << " 1 - Adicionar figurinha" << endl;
    cout << " 2 - Buscar figurinha" << endl;
    cout << " 3 - Consultar quantidade de figurinhas" << endl;
    cout << " 4 - Listar figurinhas" << endl;
    cout << " 5 - Sair do Programa" << endl;
    cout << " Digite uma opcao: ";
    cin >> option;
    return option;
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
   
}

void Program::run()
{
    char option;
    do {
    
    option = showMenu();
    switch(option)
    {
        case '1': //Adicionar figurinha
             
             break;
        case '2': // Buscar figurinha 
             break;
        case '3': // Consultar quantas tem
            break;
        case '4': // Listar figurinhas
            break;
        case '5':
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
