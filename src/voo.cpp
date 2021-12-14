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

list <Bilhete> Voo::getBilhetes() const {
    return bilhetes;
}

void Voo::addBilhete(Bilhete b) {
    bilhetes.push_back(b);
}

Voo::Voo() {
    tm Partida = {.tm_hour = -1};
    numVoo = -1;
    lotacao = -1;
    dataPartida = Partida;
    origem = "";
    destino = "";
}

void Voo::setLotacao(int l) {
    this->lotacao = l;
}

bool Voo::removeBilhete(int id) {
    list<Bilhete>::iterator iteradorBilhete = bilhetes.begin();
    for(iteradorBilhete; iteradorBilhete != bilhetes.end(); iteradorBilhete++){
        if(iteradorBilhete->getID() == id){
            bilhetes.erase(iteradorBilhete);
            return true;
        }
    }
    return false;
}


Bilhete& Voo::procurarBilhete() {

}

