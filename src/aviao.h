#ifndef AVIAO_H
#define AVIAO_H

#include "voo.h"
#include "defs.h"
#include "servico.h"
#include "input.h"
//#include "menus.h"



class Aviao {
    string const matricula;
    int const capacidade;
    list<Voo> planoVoo;
    list<Servico> servicosCompletos;
    queue<Servico> servicosParaRealizar;

public:
    Aviao();
    Aviao(string m, int c);
    int getCapacidade() const;
    string getMatricula() const;
    list<Voo>& getPlanoVoo();
    list<Servico>& getservicosCompletos();
    Servico& getServicoRealizar();
    queue<Servico>& getServicosRealizar();
    int getNumServicosRealizar();

    void addVoo(Voo v);
    void mostrarVoos();
    bool eliminarVoo(int numVoo);
    Voo& procurarVoo(int numVoo);
    void ordenarVoos(int inputOrdenarVoos);
    bool checkVoo(int numVoo);

    void addServicoRealizar(Servico &s);
    void addServicoCompleto (Servico &s);
    void realizarServico();
    void ordenarServicosCompletos(int inputOrdenarServicosCompletos);


};


#endif //PROJECT_AVIÃO_H
