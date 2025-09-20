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
    //buscando um arquivo que está em um diretório anterior ao dir corrente
    //inputFile.open("../tmp_files/output2.txt"); 
    //inputFile.open("tmp_files/output3.txt");
    
    if (inputFile.is_open())
    {
        string str1, str2;
        float f;
        int i;
        cout << "Arquivo aberto para leitura!" << endl;
        inputFile >> str1 >> str2 >> f >> i;
        cout << str1 << endl << str2 << endl << f << endl << i << endl;
        int linhas, colunas;
        int matriz[MAX_LINHAS][MAX_COLUNAS];
        inputFile >> linhas >> colunas;
        for (int i=0; i < linhas; i++)
        {
            for(int j=0; j < colunas; j++)
            {
                inputFile >> matriz[i][j];
                cout << matriz[i][j] << " ";   
            }
            cout << endl;
        }      
        inputFile.close();
    }
    else
    {
        cout << "O arquivo não foi aberto!" << endl;
    }
    return 0;
}