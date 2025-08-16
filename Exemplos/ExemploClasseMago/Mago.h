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
    ~Mago(); //Destrutor
    void andar();
    void falar(string msg);
    void invocarMagia();

};