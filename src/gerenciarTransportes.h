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
    gerenciarTransportes(): transportes(TranspTerrestre("",0.0,NotFound)){};
    void mostrarTransportes();
    bool adicionarTransporte(const TranspTerrestre& t);
    bool removerTransporte(const TranspTerrestre& t);
    bool procurarTransporte();
    const TranspTerrestre& inputTransporte();
    void showTransporteMaisProximo();
    void showTransporte(TranspTerrestre t);
    BST<TranspTerrestre>& getTransportesBST();

};


#endif //PROJECT_GERENCIARTRANSPORTES_H
