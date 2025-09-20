// Exemplo básico de leitura de arquivo utilizando ifstream

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define MAX_LINHAS 10
#define MAX_COLUNAS 10

int main()
{
    ifstream inputFile;
    inputFile.open("./output.txt");
    if (inputFile.is_open())
    {
        string linha;
        int i = 0;
        while (getline(inputFile, linha)) 
        {
            i++;
            cout << "Linha " << i << ": " << linha << endl;
        }
        //....
        inputFile.close();
    }
    else
    {
        cout << "O arquivo não foi aberto!" << endl;
    }
    return 0;
}