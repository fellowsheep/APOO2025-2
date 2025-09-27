#include "Mago.h"

Mago::Mago()
:nome(""),idade(0),escolaDeMagia("") //inicialização junto 'a assinatura do método
{
    //Inicialização dentro do bloco de código (só precisa uma das formas)
    nome="";
    idade=0;
    escolaDeMagia="";
    cout << "Mago criado com construtor padrão!" << endl;
}

Mago::Mago(string nome, int idade, string escolaDeMagia)
{
    this->nome = nome;
    this->idade = idade;
    this->escolaDeMagia = escolaDeMagia;
}

Mago::~Mago()
{
    cout << "Deixou de existir!" << endl;
}

void Mago::alterarNome(string nome)
{
    this->nome = nome;
}

void Mago::alterarIdade(int idade)
{
    this->idade = idade;
}

int Mago::retornarIdade()
{
    return idade;
}

string Mago::retornarNome()
{
    return nome;
}

void Mago::andar()
{ 
    cout << "Estou andando!" << endl;
}

void Mago::falar(string msg)
{
    cout << "Meu nome é " << this->nome << endl;
    cout << msg << endl;
}

void Mago::invocarMagia()
{
    cout << "Invocando magia!" << endl;
}

void Mago::alterarEscolaMagia(string escolaMagia)
{
    this->escolaDeMagia = escolaMagia;
}

string Mago::retornarEscolaMagia()
{
    return escolaDeMagia;
}
