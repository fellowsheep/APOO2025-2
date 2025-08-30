#include "Figurinha.h"

#define MAX_FIGURINHAS 30

class Album {

private:
    Figurinha figurinhas[MAX_FIGURINHAS];
    int quantidade;
public: 
    Album();
    ~Album();
    void adicionar(Figurinha f);
    bool possui(int nro);
    int getQuantidade();
    void listar();

};