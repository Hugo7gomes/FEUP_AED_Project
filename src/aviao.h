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
    Aviao(string m, int c);

    /**
     * este metodo fornece a capacidade maxima do Aviao
     * @return capacidade maxima do aviao
     */
    int getCapacidade() const;

    /**
     * este metodo fornece a matricula do Aviao
     * @return matricula do Aviao
     */
    string getMatricula() const;

    /**
     * este metodo fornece a lista de voos do Aviao
     * @return lista de Voos (planoVoo)
     */
    list<Voo>& getPlanoVoo();

    /**
     * este metodo fornece a lista de servicos completos
     * @return lista de servicos completos
     */
    list<Servico>& getservicosCompletos();

    /**
     * este metodo fornece o proximo servico a realizar
     * @return proximo servico a realizar
     */
    Servico& getServicoRealizar();

    /**
     * este metodo fornce a fila de servicos a realizar
     * @return fila de servicos
     */
    queue<Servico>& getServicosRealizar();

    /**
     * este metodo fornce o numero de servicos a realizar
     * @return numero de servicos a realizar
     */
    int getNumServicosRealizar();

    /**
     * este metodo adiciona um voo ao plano de Voo
     * @param v voo a adicionar
     */
    void addVoo(Voo v);

    /**
     * este metodo mostra na consola todos os numeros de Voos
     */
    void mostrarVoos();

    /**
     * este metodo elimina do planoVoo o voo com o numero de Voo recebido
     * @param numVoo numero de voo do voo a remover
     * @return o sucesso ou insucesso da remocao do voo
     */
    bool eliminarVoo(int numVoo);
    /**
     * este metodo fornece o voo a qual esta associado o numero de voo
     * @param numVoo numero de voo a procurar
     * @return voo associado ao numero de voo
     */
    Voo& procurarVoo(int numVoo);

    /**
     * este metodo ordena o plano de voo perante um comparador recebido
     * @param inputOrdenarVoos comparador para ordenar voos
     */
    void ordenarVoos(int inputOrdenarVoos);

    /**
     * este metodo verifica se existe um voo com o numero de voo recebido
     * @param numVoo numero de voo a procurar
     * @return o sucesso ou insucesso da procura do voo
     */
    bool checkVoo(int numVoo);

    /**
     * este metodo adiciona á queue de servicos a realizar um servico
     * @param s servico a adicionar
     */
    void addServicoRealizar(Servico &s);

    /**
     * este metodo adiciona um servico a lista de servicos completos
     * @param s servico a adicionar
     */
    void addServicoCompleto (Servico &s);
    /**
     * este metodo retira o proximo elemento da fila e coloca-o na lista de servicos completos
     */
    void realizarServico();
    /**
     * este metodo ordena a lista de servicos completos perante um comparador recebido
     * @param inputOrdenarServicosCompletos comparador para ordenar servicos completos
     */
    void ordenarServicosCompletos(int inputOrdenarServicosCompletos);


};


#endif //PROJECT_AVIÃO_H
