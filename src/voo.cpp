//
// Created by jpedr on 25/11/2021.
//

#include "voo.h"

Voo::Voo(int n, int lot, tm dPartida, tm durVoo, string orig, string dest) {
    numVoo = n;
    lotacao = lot;
    dataPartida = dPartida;
    origem = orig;
    destino = dest;
}


int Voo::getNumVoo() const {
    return numVoo;
}

int Voo::getLotacao() const {
    return lotacao;
}

tm Voo::getDataPartida() const {
    return dataPartida;
}

tm Voo::getDuracaoVoo() const {
    return duracaoVoo;
}

string Voo::getOrigem() const {
    return origem;
}

string Voo::getDestino() const {
    return destino;
}

list <Passageiro> Voo::getPassageiros() const {
    return passageiros;
}

void Voo::addPassageiro(Passageiro p) {
    passageiros.push_back(p);
}
