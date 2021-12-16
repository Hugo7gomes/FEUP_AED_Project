//
// Created by jpedr on 30/11/2021.
//

#include "carruagem.h"

Carruagem::Carruagem(int filaBagagem, int colunaBagagem) {
    tamanhoColuna = colunaBagagem;
    for (unsigned i = 0; i <= filaBagagem; i++) {
        stack <Bilhete> pilha;
        bagagens.push_back(pilha);
    }
}

bool Carruagem::addBagagem(Bilhete &bilhete) {
    for (stack <Bilhete> &pilha: bagagens) {
        if (pilha.size() < tamanhoColuna) {
            pilha.push(bilhete);
            return true;
        }
    }
    return false;
}

bool Carruagem::removeBagagem(Bilhete &bilhete) {
    bool removeu = false;
    for (stack <Bilhete> &pilha: bagagens) {
        stack <Bilhete> aux;
        for (unsigned i = 0; i < pilha.size(); i++) {
            if (pilha.top().getID() != bilhete.getID()) {
                aux.push(pilha.top());
                removeu = true;
            }
            pilha.pop();
        }
        pilha = aux;
    }
    return removeu;
}



