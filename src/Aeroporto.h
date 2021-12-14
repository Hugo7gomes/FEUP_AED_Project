//
// Created by jpedr on 12/12/2021.
//

#ifndef PROJECT_AEROPORTO_H
#define PROJECT_AEROPORTO_H

#include "list"
#include "aviao.h"
#include "defs.h"

struct input{
    input(string m, int c){matricula = m; capacidade = c;};

    string matricula;
    int capacidade;
};

class Aeroporto {
    list<Aviao> avioes;


public:
    void showMenu() const;
    void showMenuAlterarAviao() const;
    void showMenuVoo(Voo& v) const;
    void showAvioes();
    void verVoo(Aviao& aviao);
    int inputNumVoo(Aviao& aviao);
    void verBilhete(Voo& voo);
    void removerBilhete(Voo& voo);
    void mostrarServicoRealizar(Aviao& aviao);
    void mostrarServicosCompletos(Aviao& aviao);
    void criarServicoRealizar(Aviao& aviao);
    void realizarServico(Aviao& aviao);
    list<Aviao>& getAvioes();
    Aviao& procurarAviao();
    input inputMatriculaCapacidade();
    void addAviao(string matricula, int c);
    void removeAviao();
    void comprarBilhetes();
    void alterarAviao(Aviao& aviao);
    void criarVoo(Aviao& aviao);
    void deleteVoo(Aviao& aviao);
    Passageiro criarPassageiro();
    void run();

};


#endif //PROJECT_AEROPORTO_H
