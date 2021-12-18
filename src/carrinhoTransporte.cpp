//
// Created by jpedr on 30/11/2021.
//

#include "carrinhoTransporte.h"

carrinhoTransporte::carrinhoTransporte(int numCarruagens, int filaBagagem, int colunaBagagem) {
    this->filaBagagem=filaBagagem;
    this->colunaBagagem = colunaBagagem;
    for(unsigned i = 0; i <= numCarruagens; i++){
        Carruagem carruagem = Carruagem(filaBagagem, colunaBagagem);
        carruagens.push_back(carruagem);
    }
}

carrinhoTransporte::carrinhoTransporte() {

}

int carrinhoTransporte::getNumCarruagens() {
    return carruagens.size();
}

int carrinhoTransporte::getNumPilhas() {
    return filaBagagem;
}

int carrinhoTransporte::getNumMalas() {
    return colunaBagagem;
}

bool carrinhoTransporte::addBagagemCarruagem(Bilhete &bilhete) {
    for(Carruagem& carruagem : carruagens){
        if(carruagem.addBagagem(bilhete))
            return true;
    }
    return false;
}


bool carrinhoTransporte::removeBagagemCarruagem(Bilhete &bilhete) {
    for(Carruagem& carruagem : carruagens){
        if(carruagem.removeBagagem(bilhete)){
            return true;
        }
    }
    return false;
}
