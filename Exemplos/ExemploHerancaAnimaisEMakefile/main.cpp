#include "Cachorro.h"
#include "GerenciadorSom.h" // Inclui o novo gerenciador!!!

int main()
{
    // 1. Cria o gerenciador. Ele se inicializa sozinho.
    GerenciadorSom gerenciador;

    // 2. Injeta a dependência (o gerenciador) no construtor
    Cachorro cachorro("Totoro", gerenciador);
    cachorro.fazerSom();
    
    printf("Pressione Enter para sair...\n");
    getchar();

    // 3. Quando 'gerenciador' sair do escopo (fim do main),
    //    seu destrutor será chamado e a engine será liberada.
    return 0;
}