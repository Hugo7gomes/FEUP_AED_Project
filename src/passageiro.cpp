//
// Created by jpedr on 25/11/2021.
//

#include "passageiro.h"

Passageiro::Passageiro(string n, char sex, int i, int cc):nome(n), sex(sex), idade(i), CC(cc) {}

string Passageiro::getNome() const {
    return nome;
}

char Passageiro::getSex() const {
    return sex;
}

int Passageiro::getIdade() const {
    return idade;
}

int Passageiro::getCC() const {
    return CC;
}

Passageiro::Passageiro():nome(""), sex('F'), idade(0), CC(-1) {
}
