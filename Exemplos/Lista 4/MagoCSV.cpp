#include "MagoCSV.h"

MagoCSV::MagoCSV()
{
}

MagoCSV::~MagoCSV()
{
}

void MagoCSV::serialize(Mago *magos, int nroMagos)
{
    ofstream outputFile;
    outputFile.open("magos2.csv");
    if (outputFile.is_open())
    {
        for (int i=0; i<nroMagos; i++)
        {
            outputFile << magos[i].retornarNome() << "," << magos[i].retornarIdade() << "," << magos[i].retornarEscolaMagia() << endl;
        }

        outputFile.close();
    }
    else
    {
        cout << "Não conseguiu abrir para escrita!" << endl;
    }
}

Mago *MagoCSV::deserialize(string filePath, int &nroMagos)
{
    Mago *magos = nullptr; //array dinâmico de magos
   
    ifstream inputFile;
    inputFile.open(filePath);
    if (inputFile.is_open())
    {
         magos = new Mago[MAX_MAGOS]; //array dinâmico
         string line;
         int i = 0;
         while (getline(inputFile,line)) //enquanto houver linhas
         {
            stringstream ss(line);
            //Alimentar um objeto da classe mago
            string nome;
            int idade;
            string escolaMagia;
            string campo;
            getline(ss, nome, ',');
            getline(ss, campo, ',');
            idade = atoi(campo.c_str());
            getline(ss, escolaMagia, ',');
            //ss >> nome >> idade >> escolaMagia;
            magos[i].alterarNome(nome);
            magos[i].alterarIdade(idade);
            magos[i].alterarEscolaMagia(escolaMagia);
            i++;
         }
         nroMagos = i;
        inputFile.close();
    }
    else
    {
        cout << "O arquivo " << filePath << " não pode ser aberto!" << endl;
    }
    return magos;
}
