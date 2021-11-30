//
// Created by jpedr on 30/11/2021.
//

#include "bagagem.h"

Bagagem::Bagagem(Bilhete b) {
    bilhete = b;
}

Passageiro Bagagem::getPassageiro() const {
    return bilhete.getPassageiro();
}
