//
// Created by jpedr on 25/11/2021.
//

#include "aviao.h"

Aviao::Aviao(string m, int c) : matricula(m), capacidade(c){
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
void Aviao::realizarServico() {
    servicosCompletos.push_back(getProximoServico());
    servicosParaRealizar.pop();
}

bool Aviao::eliminarVoo(int numVoo) {
    list<Voo>::iterator iteradorVoo = planoVoo.begin();
    for(iteradorVoo; iteradorVoo != planoVoo.end(); iteradorVoo++){
        if(iteradorVoo->getNumVoo() == numVoo){
            planoVoo.erase(iteradorVoo);
            return true;
        }
    }
    return false;
}

void Aviao::mostrarVoos() {
    if(planoVoo.size() == 0){
        cout << "Este aviao nao possui voos";
        return;
    }
    for(Voo& voo : planoVoo){
        cout << voo.getNumVoo() << endl;
    }
}

Voo& Aviao::procurarVoo() {
    int numVoo;

    while(true){
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Introduza o numero de Voo" << endl;
        cin >> numVoo;
        for(Voo& v : planoVoo){
            if(v.getNumVoo() == numVoo){
                return v;
            }
        }
    }
}

list <Servico> &Aviao::getservicosCompletos() {
    return servicosCompletos;
}

Servico &Aviao::getServicoRealizar() {
    return servicosParaRealizar.front();
}

int Aviao::getNumServicosRealizar() {
    return servicosParaRealizar.size();
}

void Aviao::addServicoCompleto(Servico &s) {
    servicosCompletos.push_back(s);
}
