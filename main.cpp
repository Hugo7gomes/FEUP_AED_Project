#include <iostream>

#include "src/Aeroporto.h"
#include "src/load.h"
#include "src/update.h"

int main() {
    Aeroporto aeroporto;
    Load load;
    Update update;

    load.run(aeroporto);
    aeroporto.run();
    update.run(aeroporto);


    return 0;
}
