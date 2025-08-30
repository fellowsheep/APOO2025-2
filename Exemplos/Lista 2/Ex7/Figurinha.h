#include <iostream>
#include <string>

using namespace std;

class Figurinha
{
    private:
        int nro;
        string nome;
        string Time;
    
    public:
        Figurinha();
        Figurinha(int nro, string nome, string time);
        ~Figurinha();

        //Setters - realmente precisa deles neste contexto?
        void setNro(int nro);
        void setNome(string nome);
        void setTime(string time);

        //Getters
        int getNro();
        string getNome();
        string getTime();

        void resumo();

};