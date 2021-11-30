//
// Created by jpedr on 30/11/2021.
//

#ifndef BAGAGEM_H
#define BAGAGEM_H

#include "bilhete.h"
class Bagagem {
    Bilhete bilhete;
public:
    Bagagem(Bilhete b);
    Passageiro getPassageiro() const;
};


#endif //PROJECT_BAGAGEM_H
