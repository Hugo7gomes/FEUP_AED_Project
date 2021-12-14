//
// Created by jpedr on 25/11/2021.
//

#include "passageiro.h"

Passageiro::Passageiro(string n, int i, int cc):nome(n), idade(i), CC(cc) {}

string Passageiro::getNome() const {
    return nome;
}


int Passageiro::getIdade() const {
    return idade;
}

int Passageiro::getCC() const {
    return CC;
}

Passageiro::Passageiro():nome(""), idade(0), CC(-1) {
}
