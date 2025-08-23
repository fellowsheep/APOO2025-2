#include <iostream>
#include <string>

using namespace std;

class Mago {
// Atributos
private:
    string nome;
    int idade;
    string escolaDeMagia;
// Métodos
public:
    Mago(); //Construtor padrão
    Mago(string nome, int idade, string escolaDeMagia); //construtor personalizado
    ~Mago(); //Destrutor
    //Métodos setters
    void alterarNome(string nome);
    void alterarIdade(int idade);
    //Métodos getters
    int retornarIdade();
    string retornarNome();
    void andar();
    void falar(string msg);
    void invocarMagia();

};