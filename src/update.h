//
// Created by jpedr on 15/12/2021.
//

#ifndef PROJECT_UPDATE_H
#define PROJECT_UPDATE_H

#include "gerenciarAeroportos.h"

class Update {

private:

    /**
     *
     * @param gerenciarAeroportos
     */
    void aeroporto(gerenciarAeroportos &gerenciarAeroportos);
    /**
     *
     * @param aeroporto
     */
    void avioes(Aeroporto & aeroporto);
    /**
     *
     * @param aeroporto
     */
    void voos(Aeroporto& aeroporto);
    /**
     *
     * @param aeroporto
     */
    void bilhetes(Aeroporto& aeroporto);
    /**
     *
     * @param aeroporto
     */
    void servicosCompletos(Aeroporto& aeroporto);
    /**
     *
     * @param aeroporto
     */
    void servicosRealizar(Aeroporto& aeroporto);
    /**
     *
     * @param aeroporto
     */
    void transportesTerrestres(Aeroporto& aeroporto);
public:
    /**
    *
    */
    Update();
    /**
     * este metodo é responsavel por chamar todos os metodos encarregues de dar update de informacao para os ficheiros
     * @param gerenciarAeroportos
     */
    void run(gerenciarAeroportos &gerenciarAeroportos);
};


#endif //PROJECT_UPDATE_H
