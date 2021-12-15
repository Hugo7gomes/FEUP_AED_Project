#include <iostream>

#include "src/Aeroporto.h"
#include "src/load.h"
int main() {
    Aeroporto aeroporto;
    Load load;
    load.avioes(aeroporto);
    load.voos(aeroporto);
    load.servicosRealizar(aeroporto);
    load.servicosCompletos(aeroporto);
    load.bilhetes(aeroporto);
    aeroporto.run();


    return 0;
}
