//
// Created by jpedr on 25/11/2021.
//

#include "bilhete.h"

Bilhete::Bilhete(Passageiro p, Voo v): passageiro(p), voo(v) {
    bagagemAuto = false;
}

Passageiro Bilhete::getPassageiro() const {
    return passageiro;
}

Voo Bilhete::getVoo() const {
    return voo;
}

bool Bilhete::getBagagenAuto() const {
    return bagagemAuto;
}

void Bilhete::setBagagemAuto() {
    bagagemAuto = true;
}