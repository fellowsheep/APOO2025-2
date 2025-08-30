#include "Program.h"

// Para compilar:
// g++ main.cpp Figurinha.cpp Album.cpp Programa.cpp -o Programa

int main()
{
    Program program;
    program.initialize();
    program.run();
    program.finish();
    return 0;
}