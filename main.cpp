#include <iostream>

#include "src/Aeroporto.h"
#include "src/load.h"
#include "src/update.h"

int main() {
    gerenciarAeroportos aeroportos;
    Load load;
    Update update;

    load.run(aeroportos);
    aeroportos.run();
    update.run(aeroportos);


    return 0;
}
