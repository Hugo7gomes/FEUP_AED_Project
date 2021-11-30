//
// Created by jpedr on 25/11/2021.
//

#include "bilhete.h"

Bilhete::Bilhete(Passageiro p, Voo v, bool b): passageiro(p), voo(v), temBagagem(b) {
    bagagemAuto = false;
}

Passageiro Bilhete::getPassageiro() const {
    return passageiro;
}

Voo Bilhete::getVoo() const {
    return voo;
}

bool Bilhete::getBagagemAuto() const {
    return bagagemAuto;
}

void Bilhete::setBagagemAuto() {
    bagagemAuto = true;
}

bool Bilhete::gettemBagagem() const {
    return temBagagem;
}

Bilhete::Bilhete(): passageiro(Passageiro()), voo(Voo()), temBagagem(false) {
}
