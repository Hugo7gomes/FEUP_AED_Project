//
// Created by jpedr on 12/12/2021.
//

#ifndef PROJECT_AEROPORTO_H
#define PROJECT_AEROPORTO_H

#include <list>
#include "aviao.h"
#include "defs.h"
#include "menus.h"
#include "input.h"
#include "bst.h"
#include "gerenciarTransportes.h"
#include "transpTerrestre.h"


class Aeroporto {
    string id;
    list<Aviao> avioes;
    gerenciarTransportes Transportes;

public:
    Aeroporto(string id);
    gerenciarTransportes& getTransportes();
    string getId();
    list<Aviao>& getAvioes();

    void tratarAvioes();
    void showAvioes();
    void addAviao(string matricula, int c);
    void criarAviao();
    void removeAviao();
    void alterarAviao();
    bool checkAviao(string matricula);
    Aviao& procurarAviao(string matricula);

    void tratarTransportes();

    void TratarVoos(Aviao &aviao);
    void verVoo(Aviao& aviao);
    void criarVoo(Aviao& aviao);
    void deleteVoo(Aviao& aviao);
    void ordenarVoos(Aviao& aviao);

    void TratarServicos(Aviao &aviao);
    void showServicoRealizar(Aviao& aviao);
    void showServicosCompletos(Aviao& aviao);
    void criarServicoRealizar(Aviao& aviao);
    void realizarServico(Aviao& aviao);

    void verBilhete(Voo& voo);
    void removerBilhete(Voo& voo);
    void comprarBilhetes();
    Passageiro criarPassageiro();

    void run();


};


#endif //PROJECT_AEROPORTO_H
