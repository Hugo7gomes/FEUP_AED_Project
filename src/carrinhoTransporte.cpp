//
// Created by jpedr on 30/11/2021.
//

#include "carrinhoTransporte.h"

carrinhoTransporte::carrinhoTransporte(int numCarruagens) {
    for(unsigned i = 0; i <= numCarruagens; i++){
        Carruagem carruagem = Carruagem(0, 0);
        carruagens.push_back(carruagem);
    }
}
