#include <iostream>
#include <ctime>
#include "Album.h"

using namespace std;

const Figurinha figurinhasData[MAX_FIGURINHAS] = {
    Figurinha(1,"Pelé","Santos"),
    //...preencher com algumas
};

class Program
{
    private:
       Album album;
       char showMenu();
    public:
        Program();
        ~Program();
        void initialize();
        void run();
        void finish();

};