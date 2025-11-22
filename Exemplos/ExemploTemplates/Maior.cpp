#include <iostream>

using namespace std;

template <typename T> 
T maximo(T a, T b)
{
    if (a > b) return a;
    else return b;
}


int main()
{
    cout << endl;
    int a=10, b=5;
    cout << maximo(a, b) << endl;

    float c= 1.2, d = 3.14;
    cout << maximo(c, d) << endl;

    double e=5.6, f=102.0;
    cout << maximo(e, f) << endl;

    char g='A', h='Z';
    cout << maximo(g, h) << endl;


    return 0;
}