#include <iostream>
#include <fstream>
#include <sstream>

#include "Mago.h"

using namespace std;

#define MAX_MAGOS 50

class MagoCSV
{
    public:
        MagoCSV();
        ~MagoCSV();
        void serialize(Mago *magos, int nroMagos);
        Mago* deserialize(string filePath, int &nroMagos);

};