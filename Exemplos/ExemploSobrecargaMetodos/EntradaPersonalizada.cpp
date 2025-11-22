#include <iostream>

using namespace std;

class Gerenciadora
{
    private:
        int a, b, c;
    
    public:
    Gerenciadora() {}
    void inicializar();
    void inicializar(int v1);
    void inicializar(int v1, int v2);
    void inicializar(int v1, int v2, int v3);
    int inicializar(char a);
    void print();
};

void Gerenciadora::inicializar()
{
    a = 0;
    b = 0;
    c = 0;
}

void Gerenciadora::inicializar(int v1)
{
    a = v1;
    b = 0;
    c = 0;
}

void Gerenciadora::inicializar(int v1, int v2)
{
    a = v1;
    b = v2;
    c = 0;
}

void Gerenciadora::inicializar(int v1, int v2, int v3)
{
    a = v1;
    b = v2;
    c = v3;
}

int Gerenciadora::inicializar(char a)
{
    return 0;
}

void Gerenciadora::print()
{
    cout << "[" << a << ", " << b << ", " << c << "]" << endl; 
}

int main()
{
    Gerenciadora g;
    g.inicializar();
    g.print();

    g.inicializar(1);
    g.print();

    g.inicializar(2,1);
    g.print();

    g.inicializar(3,2,1);
    g.print(); 

    g.inicializar('a');

    return 0;
}

