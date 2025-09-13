#include<iostream>
#include<clocale>

using namespace std;

struct Ponto 
{
    float x, y;
};

int main()
{

    Ponto P1, P2;
    cout << "Digite as coords x e y de P1: ";
    cin >> P1.x >> P1.y;
    cout << "Digite as coords x e y de P2: ";
    cin >> P2.x >> P2.y;
    
    int n;
    cout << endl << "Digite o nro de pontos entre P1 e P2: ";
    cin >> n;

    // Alocar dinamicamente n Pontos em um array
    Ponto *pontos = new Ponto[n];

    float deltaT = 1.0 / (float) (n-1) ;

    //cout << deltaT << endl;

    for (int i=0; i < n; i++)
    {
        float ti = i * deltaT;
        //cout << "ti = " << ti << endl;
        pontos[i].x = P1.x + ti * (P2.x - P1.x);
        pontos[i].y = P1.y + ti * (P2.y - P1.y);
        cout << pontos[i].x << " " << pontos[i].y << endl;
    }

    return 0;
}