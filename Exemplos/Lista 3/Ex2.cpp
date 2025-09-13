#include<iostream>
#include<clocale>
#include<cmath>

#define Pi 3.14

using namespace std;

struct Ponto 
{
    float x, y;
};

int main()
{
    float r;
    cout << "Digite o raio do circulo: " << endl;
    cin >> r;
    
    int n;
    cout << endl << "Digite o nro de pontos: ";
    cin >> n;

    // Alocar dinamicamente n Pontos em um array
    Ponto *pontos = new Ponto[n];

    float deltaT = 2 * Pi / (float) (n) ;

    //cout << deltaT << endl;

    for (int i=0; i < n; i++)
    {
        float ti = i * deltaT;
        //cout << "ti = " << ti << endl;
        pontos[i].x = cos(ti) * r;
        pontos[i].y = sin(ti) * r;
        cout << pontos[i].x << " " << pontos[i].y << endl;
    }

    return 0;
}