//
// Created by jpedr on 30/11/2021.
//

#ifndef CARRINHOTRANSPORTE_H
#define CARRINHOTRANSPORTE_H

#include "carruagem.h"

class carrinhoTransporte {
        vector<Carruagem> carruagens;
        int filaBagagem, colunaBagagem;
public:
    carrinhoTransporte();
    carrinhoTransporte(int numCarruagens, int filaBagagem, int colunaBagagem);
    bool addBagagemCarruagem(Bilhete &bilhete);
    int getNumCarruagens();
    int getNumPilhas();
    int getNumMalas();
    bool removeBagagemCarruagem(Bilhete &bilhete);
};


#endif //PROJECT_CARRINHOTRANSPORTE_H
