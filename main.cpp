#include <iostream>

#include "src/Aeroporto.h"
#include "src/load.h"
#include "src/update.h"
#include "src/gerenciarTransportes.h"

int main() {
    gerenciarTransportes transportes;
    Aeroporto aeroporto(transportes);
    Load load;
    Update update;

    load.run(aeroporto);
    aeroporto.run();
    update.run(aeroporto);


    return 0;
}
