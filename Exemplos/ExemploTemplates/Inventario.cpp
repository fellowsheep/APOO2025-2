#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Classes do nosso mundo RPG
class Pocao {
public:
    string tipo;
    int cura;
    // Para facilitar o cout depois
    friend ostream& operator<<(ostream& os, const Pocao& p) {
        return os << "Pocao de " << p.tipo << " (+" << p.cura << " HP)";
    }
};

class Arma {
public:
    string nome;
    int dano;
    friend ostream& operator<<(ostream& os, const Arma& a) {
        return os << "Arma: " << a.nome << " (Dano: " << a.dano << ")";
    }
};

// T representa o tipo de item que vamos guardar (Pocao, Arma, int, string...)
template <typename T>
class Inventario {
private:
    T* itens;           // Array dinâmico do tipo T
    int capacidade;
    int quantidade;

public:
    Inventario(int cap) {
        capacidade = cap;
        quantidade = 0;
        itens = new T[capacidade]; // Alocação dinâmica baseada em T
    }

    ~Inventario() {
        delete[] itens;
    }

    // Método para adicionar itens ao inventário
    bool guardar(T item) {
        if (quantidade < capacidade) {
            itens[quantidade] = item;
            quantidade++;
            return true;
        }
        return false;
    }

    // Método para listar (assume que T tem overload do << ou é primitivo)
    void listarConteudo() {
        cout << "--- Inventario ---" << endl;
        for (int i = 0; i < quantidade; i++) {
            cout << "[" << i << "]: " << itens[i] << endl;
        }
        cout << "------------------" << endl;
    }
    
    // Exemplo de método que retorna T
    T* pegarItem(int indice) {
        if (indice >= 0 && indice < quantidade) {
            return &itens[indice];
        }
        return nullptr;
    }
};

int main() {
    // 1. Inventário de Poções (T vira Pocao)
    Inventario<Pocao> bolsaDePocoes(5);
    
    bolsaDePocoes.guardar({"Vida", 50});
    bolsaDePocoes.guardar({"Mana", 30});
    
    bolsaDePocoes.listarConteudo();

    // 2. Inventário de Armas (T vira Arma) - Reuso total de código!
    Inventario<Arma> arsenal(3);
    
    arsenal.guardar({"Excalibur", 100});
    arsenal.guardar({"Adaga", 20});
    
    arsenal.listarConteudo();

    // 3. Mostrando que funciona com primitivos (conexão com int, float)
    Inventario<int> pontuacoes(10);
    pontuacoes.guardar(1500);
    pontuacoes.guardar(500);
    pontuacoes.guardar(5000);
    pontuacoes.listarConteudo();

    return 0;
}