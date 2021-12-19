//
// Created by jpedr on 17/12/2021.
//

#ifndef PROJECT_GERENCIARAEROPORTOS_H
#define PROJECT_GERENCIARAEROPORTOS_H
#include "Aeroporto.h"
#include "input.h"

class gerenciarAeroportos {
    list<Aeroporto> aeroportos;
public:
    /**
     * Construtor default da classe gerenciarAeroportos
     */
    gerenciarAeroportos();

    /**
     * Este método fornece a lista dos Aeroportos
     * @return lista de aeroportos
     */
    list<Aeroporto>& getAeroportos();

    /**
     * Este método pede ao utilizador o id do aeroporto e acede ao mesmo
     */
    void verAeroporto();

    /**
     * Este método mostra na consola todos os aeroportos existentes
     */
    void showAeroportos();

    /**
     * Este método cria um aeroporto
     */
    void criarAeroporto();

    /**
     * Este método adiciona um aeroporto a lista de aeroportos
     * @param aeroporto aeroporto a adicionar à lista
     */
    void adicionarAeroporto(Aeroporto aeroporto);

    /**
     * Este método remove um aeroporto da lista de aeroportos
     */
    void removerAeroporto();

    /**
     * Este método verifica se existe um aeroporto com o id de aeroporto recebido
     * @param id id do aeroporto a procurar
     * @return true se existir
     */
    bool checkAeroporto(string id);

    /**
     *Este método apresenta as opcoes do menu principal no que toca a gerenciar aeroportos
     */
    void run();
};


#endif //PROJECT_GERENCIARAEROPORTOS_H
