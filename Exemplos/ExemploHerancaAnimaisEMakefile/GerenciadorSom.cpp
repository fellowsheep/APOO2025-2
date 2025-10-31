// Esta é a ÚNICA implementação que precisa desta define
#define MINIAUDIO_IMPLEMENTATION // Só pode ter isso 1 vez!
#include "GerenciadorSom.h"
#include <iostream>

GerenciadorSom::GerenciadorSom() : inicializadoComSucesso(false)
{
    ma_result result = ma_engine_init(NULL, &engine);
    if (result != MA_SUCCESS) {
        printf("Falha ao inicializar a engine de áudio.\n");
    } else {
        inicializadoComSucesso = true;
    }
}

GerenciadorSom::~GerenciadorSom()
{
    if (inicializadoComSucesso) {
        ma_engine_uninit(&engine);
    }
}

void GerenciadorSom::tocarSom(string nomeArquivo)
{
    if (!inicializadoComSucesso) {
        printf("Engine de áudio não inicializada. Não é possível tocar som.\n");
        return;
    }
    
    // O som será liberado da memória automaticamente quando terminar de tocar
    ma_engine_play_sound(&engine, nomeArquivo.c_str(), NULL);
}