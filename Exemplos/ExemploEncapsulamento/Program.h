#include <iostream>
#include <ctime>

using namespace std;

class Program
{
    private:
        int nCommons, nRares, nLengendaries;
        char showMenu();
        void openBox();
        void showInfo();
    public:
        Program();
        ~Program();
        void initialize();
        void run();
        void finish();

};