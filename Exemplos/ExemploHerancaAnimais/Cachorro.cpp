#include "Cachorro.h"

Cachorro::Cachorro(string nome,ma_engine *engine) : Animal(nome)
{
    this->engine = engine;
    cout << "Cachorro " << this->nome << " foi criado!" << endl;
}

void Cachorro::fazerSom()
{
    cout << "Au au!!" << endl;

    // O som será liberado da memória automaticamente quando terminar de tocar
    ma_engine_play_sound(engine, "Bluthund_jault.mp3", NULL);

}

