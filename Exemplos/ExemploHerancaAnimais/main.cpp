#include "Cachorro.h"

int main()
{

    ma_result result;
    ma_engine engine;

    //Inicializando a biblioteca miniaudio
    result = ma_engine_init(NULL, &engine);
    if (result != MA_SUCCESS) {
        printf("Failed to initialize audio engine.\n");
        return -1;
    }


    //Animal animal("Totó"); NÃO PODE PORQUE É ABSTRATA

    Cachorro cachorro("Totoro", &engine);
    cachorro.fazerSom();

    
    // Mantém o programa rodando para o som poder tocar.
    // Em um programa real (com loop de eventos, por ex.), isso não seria necessário.
    printf("Pressione Enter para sair...\n");
    getchar();

    //Libera a memória do motor de som
    ma_engine_uninit(&engine);
    return 0;
}
