#include <iostream>

#include "src/Aeroporto.h"
#include "src/load.h"
#include "src/update.h"

int main() {
    Aeroporto aeroporto;
    Load load;
    Update update;
    load.avioes(aeroporto);
    load.voos(aeroporto);
    load.servicosRealizar(aeroporto);
    load.servicosCompletos(aeroporto);
    load.bilhetes(aeroporto);
    aeroporto.run();
    update.avioes(aeroporto);


    return 0;
}
