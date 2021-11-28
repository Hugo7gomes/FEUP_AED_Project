//
// Created by jpedr on 25/11/2021.
//

#include "aviao.h"

Aviao::Aviao(string m, int c, list<Voo> planoVoo) : matricula(m), capacidade(c), planoVoo(planoVoo){}

int Aviao::getCapacidade() const {
    return capacidade;
}

string Aviao::getMatricula() const {
    return matricula;
}

list <Voo> Aviao::getPlanoVoo() const {
    return planoVoo;
}

void Aviao::addVoo(Voo v) {
    planoVoo.push_back(v);
}
