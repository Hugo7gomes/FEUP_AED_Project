//
// Created by jpedr on 30/11/2021.
//

#ifndef PROJECT_CARRUAGEM_H
#define PROJECT_CARRUAGEM_H
#include "bilhete.h"

class Carruagem {
    vector<stack<Bilhete>> bagagens;
    int tamanhoColuna;
public:
    Carruagem(int filaBagagem, int colunaBagagem);
    void addBagagem(Bilhete& bilhete);
};


#endif //PROJECT_CARRUAGEM_H
