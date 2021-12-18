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
    /**
     * Construtor da class Carruagem
     * @param filaBagagem número de pilhas
     * @param colunaBagagem número de malas por pilha
     */
    Carruagem(int filaBagagem, int colunaBagagem);
    /**
     * Este metodo indica se uma bagagem é adicionada a pilha
     * @param bilhete
     * @return true se a bagagem tiver sido adicionada com sucesso
     */
    bool addBagagem(Bilhete& bilhete);
    /**
     * Este metodo indica se uma bagagem é removida da pilha
     * @param bilhete
     * @return true se a bagagem tiver sido removida com sucesso
     */
    bool removeBagagem(Bilhete& bilhete);
};


#endif //PROJECT_CARRUAGEM_H
