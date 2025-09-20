// Exemplo básico de escrita de arquivo utilizando ofstream

#include <iostream>
#include <fstream>

using namespace std;

int main()
{

    //Criação de uma variável para usar uma stream de saída de arquivo
    ofstream outputFile;
    outputFile.open("output.txt");

    if (outputFile.is_open())
    {
        outputFile <<  "Ola mundo!" << endl;
        float Pi = 3.14;
        int a = 100;
        outputFile << Pi << " " << a << endl;
        outputFile.close();
        cout << "Arquivo output.txt criado com sucesso!" << endl;
    }
    else
    {
        cout << "Arquivo output.txt não pode ser aberto para escrita!" << endl;
    }

    return 0;
}