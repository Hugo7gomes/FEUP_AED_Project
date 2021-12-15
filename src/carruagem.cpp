//
// Created by jpedr on 30/11/2021.
//

#include "carruagem.h"

Carruagem::Carruagem(int filaBagagem, int colunaBagagem) {
    tamanhoColuna = colunaBagagem;
    for(unsigned i = 0; i <= filaBagagem; i++){
        stack<Bilhete> pilha;
        bagagens.push_back(pilha);
    }
}

void Carruagem::addBagagem(Bilhete &bilhete) {
    for(stack<Bilhete>& pilha : bagagens){
        if(pilha.size() < tamanhoColuna){
            pilha.push(bilhete);
            break;
        }
    }
}


