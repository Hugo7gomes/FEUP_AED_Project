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
    /**
     * Construtor default da classe carrinhoTransporte
     */
    carrinhoTransporte();
    /**
     * Construtor da class carrinhoTransporte
     * @param numCarruagens número de carruagens
     * @param filaBagagem número de pilhas
     * @param colunaBagagem número de malas por pilha
     */
    carrinhoTransporte(int numCarruagens, int filaBagagem, int colunaBagagem);
    /**
     * Este método fornece o número de carruagens do carrinho
     * @return número de carruagens
     */
    int getNumCarruagens();
    /**
     * Este método fornece o número de pilhas de cada carruagens
     * @return número de pilhas
     */
    int getNumPilhas();
    /**
     * Este método fornece o número de malas de cada pilha
     * @return número de malas
     */
    int getNumMalas();
    /**
     * Este método indica se uma bagagem é adicionada ao carrinho
     * @param bilhete
     * @return true se a bagagem tiver sido adicionada com sucesso
     */
    bool addBagagemCarruagem(Bilhete &bilhete);
    /**
     * Este método indica se uma bagagem é removida do carrinho
     * @param bilhete
     * @return true se a bagagem tiver sido removida com sucesso
     */
    bool removeBagagemCarruagem(Bilhete &bilhete);
};


#endif //PROJECT_CARRINHOTRANSPORTE_H
