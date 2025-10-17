#define MINIAUDIO_IMPLEMENTATION
#include "miniaudio.h"

#include <stdio.h>

int main()
{
    ma_result result;
    ma_engine engine;

    result = ma_engine_init(NULL, &engine);
    if (result != MA_SUCCESS) {
        printf("Failed to initialize audio engine.\n");
        return -1;
    }

    // O som será liberado da memória automaticamente quando terminar de tocar
    ma_engine_play_sound(&engine, "huehner.mp3", NULL);

    // Mantém o programa rodando para o som poder tocar.
    // Em um programa real (com loop de eventos, por ex.), isso não seria necessário.
    printf("Pressione Enter para sair...\n");
    getchar();

    ma_engine_uninit(&engine);

    return 0;
}