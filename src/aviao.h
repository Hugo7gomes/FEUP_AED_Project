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
    /**
     * Construtor default da classe Aviao
     */
    Aviao();

    /**
     * Construtor da classe Aviao
     * @param m matricula do Aviao
     * @param c capacidade maxima do Aviao
     */
    Aviao(string matricula, int capacidade);

    /**
     * Este método fornece a capacidade maxima do Aviao
     * @return capacidade maxima do aviao
     */
    int getCapacidade() const;

    /**
     * Este método fornece a matricula do Aviao
     * @return matricula do Aviao
     */
    string getMatricula() const;

    /**
     * Este método fornece a lista de voos do Aviao
     * @return lista de Voos (planoVoo)
     */
    list<Voo>& getPlanoVoo();

    /**
     * Este método fornece a lista de servicos completos
     * @return lista de servicos completos
     */
    list<Servico>& getServicosCompletos();

    /**
     * Este método fornece o proximo servico a realizar
     * @return proximo servico a realizar
     */
    Servico& getServicoRealizar();

    /**
     * Este método fornce a fila de servicos a realizar
     * @return fila de servicos
     */
    queue<Servico>& getServicosRealizar();

    /**
     * Este método fornce o numero de servicos a realizar
     * @return numero de servicos a realizar
     */
    int getNumServicosRealizar();

    /**
     * Este método adiciona um voo ao plano de Voo
     * @param v voo a adicionar
     */
    void addVoo(Voo v);

    /**
     * Este método mostra na consola todos os numeros de Voos
     */
    void mostrarVoos();

    /**
     * Este método elimina do planoVoo o voo com o numero de Voo recebido
     * @param numVoo numero de voo do voo a remover
     * @return o sucesso ou insucesso da remocao do voo
     */
    bool eliminarVoo(int numVoo);
    /**
     * Este método fornece o voo a qual esta associado o numero de voo
     * @param numVoo numero de voo a procurar
     * @return voo associado ao numero de voo
     */
    Voo& procurarVoo(int numVoo);

    /**
     * Este método ordena o plano de voo perante um comparador recebido
     * @param inputOrdenarVoos comparador para ordenar voos
     */
    void ordenarVoos(int inputOrdenarVoos);

    /**
     * Este método verifica se existe um voo com o numero de voo recebido
     * @param numVoo numero de voo a procurar
     * @return o sucesso ou insucesso da procura do voo
     */
    bool checkVoo(int numVoo);

    /**
     * Este método adiciona à queue de servicos a realizar um servico
     * @param s servico a adicionar
     */
    void addServicoRealizar(Servico &s);

    /**
     * Este método adiciona um servico a lista de servicos completos
     * @param s servico a adicionar
     */
    void addServicoCompleto (Servico &s);
    /**
     * Este método retira o proximo elemento da fila e coloca-o na lista de servicos completos
     */
    void realizarServico();
    /**
     * Este método ordena a lista de servicos completos perante um comparador recebido
     * @param inputOrdenarServicosCompletos comparador para ordenar servicos completos
     */
    void ordenarServicosCompletos(int inputOrdenarServicosCompletos);


};


#endif //PROJECT_AVIÃO_H
