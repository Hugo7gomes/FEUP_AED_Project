//
// Created by jpedr on 30/11/2021.
//

#ifndef PROJECT_CARRUAGEM_H
#define PROJECT_CARRUAGEM_H
#include "bilhete.h"

class Carruagem {
    list<stack<Bilhete>> bagagens;
public:
    Carruagem(int n, int m);
};


#endif //PROJECT_CARRUAGEM_H
