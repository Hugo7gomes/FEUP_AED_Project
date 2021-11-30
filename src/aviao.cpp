//
// Created by jpedr on 25/11/2021.
//

#include "aviao.h"

Aviao::Aviao(string m, int c, list<Voo> planoVoo) : matricula(m), capacidade(c), planoVoo(planoVoo){
    list<Servico> servCompletos;
    servicosCompletos =servCompletos;
    queue<Servico> servRealizar;
    servicosParaRealizar = servRealizar;
}

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

void Aviao::addServicoRealizar(Servico &s) {
    servicosParaRealizar.push(s);
}


Servico Aviao::getProximoServico() const{
    return servicosParaRealizar.front();
}

//adiciona serviço realizado aos completos e retira da queue
void Aviao::addServicoCompleto(Servico s) {
    servicosCompletos.push_back(getProximoServico());
    servicosParaRealizar.pop();
}
