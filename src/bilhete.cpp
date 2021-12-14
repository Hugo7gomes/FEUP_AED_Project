//
// Created by jpedr on 25/11/2021.
//

#include "bilhete.h"

int Bilhete :: idAux = 1;

Bilhete::Bilhete(Passageiro p, bool b): passageiro(p), temBagagem(b) {
    bagagemAuto = false;
    id = idAux;
    idAux++;
}

Passageiro Bilhete::getPassageiro() const {
    return passageiro;
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
int Bilhete::getID() {
    return id;
}
Bilhete::Bilhete(): passageiro(Passageiro()), temBagagem(false) {
}
