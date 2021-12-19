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
    /**
     * construtor da classe aeroporto
     * @param id id do aeroporto
     */
    Aeroporto(string id);
    /**
     * Este método fornece um gerenciador de transportes
     * @return gerenciar transportes
     */
    gerenciarTransportes& getTransportes();
    /**
     * Este método fornece o id do aeroporto
     * @return id do aeroporto
     */
    string getId();
    /**
     * Este método fornece a lista com todos os aviões do aeroporto
     * @return lista de aviões
     */
    list<Aviao>& getAvioes();

    /**
     * Este método fornece as possiveis opçoes a realizar no aeroporto no que toca aos aviões
     */
    void tratarAvioes();
    /**
     * Este método mostra os aviões na consola ordenados consoante a escolha do utilizador
     */
    void showAvioes();
    /**
     * Este método adiciona um aviao ao aeroporto
     * @param matricula matricula do aviao a ser adicionado
     * @param c capacidade do aviao a ser adicionado
     */
    void addAviao(string matricula, int capacidade);
    /**
     * Este método cria um aviao com uma matricula e capacidade especificados pelo utilizador
     */
    void criarAviao();
    /**
     * Este método remove um aviao do aeroporto
     */
    void removeAviao();
    /**
     * Este método fornece as possiveis opçoes a realizar num avião
     */
    void alterarAviao();
    /**
     * Este método indica se o aviao existe ou nao
     * @param matricula matricula do aviao a verificar se existe
     * @return true se o aviao existe
     */
    bool checkAviao(string matricula);
    /**
     * Este método fornece o aviao com a matricula recebida
     * @param matricula matricula do aviao a ser procurado
     * @return o aviao
     */
    Aviao& procurarAviao(string matricula);

    /**
     * Este método fornece as possiveis opçoes a realizar em transportes
     */
    void tratarTransportes();

    /**
     * Este método fornece as possiveis opçoes a realizar num voo
     * @param aviao aviao em que se encontra o voo
     */
    void tratarVoos(Aviao &aviao);
    /**
     * Este método fornece as possiveis opçoes a realizar em bilhetes
     * @param aviao aviao com o voo que contem os bilhetes
     */
    void verVoo(Aviao& aviao);
    /**
     * Este método cria um aviao com as especificacoes dadas pelo utilizador
     * @param aviao aviao aonde criar o voo
     */
    void criarVoo(Aviao& aviao);
    /**
     * Este método remove um voo do aviao
     * @param aviao aviao aonde remover o voo
     */
    void deleteVoo(Aviao& aviao);
    /**
     * Este método ordena os voos consoante a escolha do utilizador
     * @param aviao aviao aonde ordenar os voos
     */
    void ordenarVoos(Aviao& aviao);

    /**
     * Este método fornece as possiveis opçoes a realizar em servicos
     * @param aviao aviao aonde se encontra o voo com os servicos
     */
    void tratarServicos(Aviao &aviao);
    /**
     * Este método mostra o proximo servico a ser realizado
     * @param aviao aviao aonde se encontra o voo com os servicos a realizar
     */
    void showServicoRealizar(Aviao& aviao);
    /**
     * Este método mostra todos os servicos completos
     * @param aviao aviao aonde se encontra o voo com os servicos completos
     */
    void showServicosCompletos(Aviao& aviao);
    /**
     * Este método cria um servico com as especificacoes dadas pelo utilizador
     * @param aviao aviao com o voo aonde adicionar o servico a realizar
     */
    void criarServicoRealizar(Aviao& aviao);
    /**
     * Este método realiza o proximo o proximo servico na fila de servicos a realizar
     * @param aviao aviao com o voo aonde se encontra o proximo servico a realizar
     */
    void realizarServico(Aviao& aviao);

    /**
     * Este método mostra na consola os detalhes do bilhete com o id escolhido pelo utilizador
     * @param voo voo com os bilhetes
     */
    void verBilhete(Voo& voo);
    /**
     * Este método remove o bilhete com o id especificado pelo utilizador
     * @param voo com o bilhete a remover
     */
    void removerBilhete(Voo& voo);
    /**
     * Este método cria um ou mais bilhetes com as especifaçoes dadas pelo utilizador
     */
    void comprarBilhetes();
    /**
     * Este método cria um passageiro
     * @return passageiro criado
     */
    Passageiro criarPassageiro();

    /**
     * Este método fornece as possiveis opçoes a realizar dentro do aeroporto
     */
    void run();


};


#endif //PROJECT_AEROPORTO_H
