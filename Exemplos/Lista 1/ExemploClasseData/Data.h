#include <iostream>
#include <string>

using namespace std; //pra não precisar escrever o std:: antes

class Data {

private:
    int dia, mes, ano;

public:
    Data(int d, int m, int a);
    ~Data();
    void imprimirData();
    void imprimirDataPorExtenso(string cidade);


};