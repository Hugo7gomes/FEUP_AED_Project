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
     * este metodo fornece um gerenciador de transportes
     * @return gerenciar transportes
     */
    gerenciarTransportes& getTransportes();
    /**
     * este metodo fornece o id do aeroporto
     * @return id do aeroporto
     */
    string getId();
    /**
     * este metodo fornece a lista com todos os avioes do aeroporto
     * @return lista de avioes
     */
    list<Aviao>& getAvioes();

    /**
     * este metodo fornece as possiveis opcoes a realizar no aeroporto no que toca aos avioes
     */
    void tratarAvioes();
    /**
     * Este metodo mostra os avioes na consola ordenados consoante a escolha do utilizador
     */
    void showAvioes();
    /**
     * este metodo adiciona um aviao ao aeroporto
     * @param matricula matricula do aviao a ser adicionado
     * @param c capacidade do aviao a ser adicionado
     */
    void addAviao(string matricula, int c);
    /**
     * este metodo cria um aviao com uma matricula e capacidade especificados pelo utilizador
     */
    void criarAviao();
    /**
     * este metodo remove um aviao do aeroporto
     */
    void removeAviao();
    /**
     * este metodo fornece as possiveis opcoes a realizar num aviao
     */
    void alterarAviao();
    /**
     * este metodo indica se o aviao existe ou nao
     * @param matricula matricula do aviao a verificar se existe
     * @return true se o aviao existe
     */
    bool checkAviao(string matricula);
    /**
     * este metodo fornece o aviao com a matricula recebida
     * @param matricula matricula do aviao a ser procurado
     * @return o aviao
     */
    Aviao& procurarAviao(string matricula);

    /**
     * este metodo fornece as possiveis opcoes a realizar em transportes
     */
    void tratarTransportes();

    /**
     * este metodo fornece as possiveis opcoes a realizar num voo
     * @param aviao aviao em que se encontra o voo
     */
    void TratarVoos(Aviao &aviao);
    /**
     * este metodo fornece as possiveis opcoes a realizar em bilhetes
     * @param aviao aviao com o voo que contem os bilhetes
     */
    void verVoo(Aviao& aviao);
    /**
     * este metodo cria um aviao com as especificacoes dadas pelo utilizador
     * @param aviao aviao aonde criar o voo
     */
    void criarVoo(Aviao& aviao);
    /**
     * este metodo remove um voo do aviao
     * @param aviao aviao aonde remover o voo
     */
    void deleteVoo(Aviao& aviao);
    /**
     * este metodo mostra os voos na consola organizados consoante a escolha do utilizador
     * @param aviao aviao aonde ordenar os voos
     */
    void ordenarVoos(Aviao& aviao);

    /**
     * este metodo fornece as possiveis opcoes a realizar em servicos
     * @param aviao aviao aonde se encontra o voo com os servicos
     */
    void TratarServicos(Aviao &aviao);
    /**
     * este metodo mostra o proximo servico a ser realizado
     * @param aviao aviao aonde se encontra o voo com os servicos a realizar
     */
    void showServicoRealizar(Aviao& aviao);
    /**
     * este metodo mostra todos os servicos completos
     * @param aviao aviao aonde se encontra o voo com os servicos completos
     */
    void showServicosCompletos(Aviao& aviao);
    /**
     * este metodo cria um servico com as especificacoes dadas pelo utilizador
     * @param aviao aviao com o voo aonde adicionar o servico a realizar
     */
    void criarServicoRealizar(Aviao& aviao);
    /**
     * este metodo realiza o proximo o proximo servico na fila de servicos a realizar
     * @param aviao aviao com o voo aonde se encontra o proximo servico a realizar
     */
    void realizarServico(Aviao& aviao);

    /**
     * este metodo mostra na consola os detalhes do bilhete com o id escolhido pelo utilizador
     * @param voo voo com os bilhetes
     */
    void verBilhete(Voo& voo);
    /**
     * este metodo remove o bilhete com o id especificado pelo utilizador
     * @param voo com o bilhete a remover
     */
    void removerBilhete(Voo& voo);
    /**
     * este metodo cria um ou mais bilhetes com as especifacoes dadas pelo utilizador
     */
    void comprarBilhetes();
    /**
     * este metodo cria um passageiro
     * @return passageiro criado
     */
    Passageiro criarPassageiro();

    /**
     *este metodo fornece as possiveis opcoes a realizar dentro do aeroporto
     */
    void run();


};


#endif //PROJECT_AEROPORTO_H
