//
// Created by jpedr on 17/12/2021.
//

#ifndef PROJECT_GERENCIARTRANSPORTES_H
#define PROJECT_GERENCIARTRANSPORTES_H

#include "defs.h"
#include "transpTerrestre.h"
#include "input.h"
#include "bst.h"



class gerenciarTransportes {
    BST<TranspTerrestre> transportes;
    tm NotFound{0,0,0,1,1,80};
public:
    /**
     * construtor da classe gereneciarTransportes que inicializa a BST transportes com o elemento NotFound
     */
    gerenciarTransportes(): transportes(TranspTerrestre("",0.0,NotFound)){};
    /**
     * Este método mostra todos os transportes disponiveis no aeroporto
     */
    void showTransportes();
    /**
     * Este método retorna true ou nao consoante tenha sido possivel adicionar o transporte
     * @param t transporte a adicionar
     * @return true caso tenha sido possivel adicionar um transporte
     */
    bool adicionarTransporte(const TranspTerrestre& t);
    /**
     * Este método retorna true ou nao consoante tenha sido possivel remover o transporte
     * @param t transporte a remover
     * @return true casp tenha sido possivel remover um transporte
     */
    bool removerTransporte(const TranspTerrestre& t);
    /**
     * Este método procura o transporte especificado pelo utilizador e caso o encontre retorna true e mostra-o na consola.
     * Caso nao encontre mostra o proximo transporte mais proximo e retorna false
     * @return true caso encontre o transporte especificado pelo utilizador
     */
    bool procurarTransporte();
    /**
     * Este método recebe as especificacoes do transporte e guarda-as em t
     * @param t transporte aonde sao guaradadas as especificacoes
     */
    void inputTransporte(TranspTerrestre& t);
    /**
     * Este método mostra na consola o transporte mais proximo do aeroporto
     */
    void showTransporteMaisProximo();
    /**
     * Este método mostra na consola as especificacoes do transporte t
     * @param t transporte a ser mostrado na consola
     */
    void showTransporte(TranspTerrestre t);
    /**
     * Este método retorna a BST de transportes
     * @return a BST de transportes
     */
    BST<TranspTerrestre>& getTransportesBST();

};


#endif //PROJECT_GERENCIARTRANSPORTES_H
