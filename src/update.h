//
// Created by jpedr on 15/12/2021.
//

#ifndef PROJECT_UPDATE_H
#define PROJECT_UPDATE_H

#include "gerenciarAeroportos.h"

class Update {

private:

    /**
     * Este método da update do ficheiro do aeroporto
     * @param gerenciarAeroportos gerenciador de aeroportos
     */
    void aeroporto(gerenciarAeroportos &gerenciarAeroportos);
    /**
     * Este método da update dos ficheiros dos aviões do aeroporto correspondente
     * @param aeroporto aeroporto onde se encontram os aviões
     */
    void avioes(Aeroporto & aeroporto);
    /**
     *Este método da update dos ficheiros dos voos do aeroporto correspondente
     * @param aeroporto aeroporto onde se encontram os aviões que tem os voos
     */
    void voos(Aeroporto& aeroporto);
    /**
     * Este método da update dos ficheiros dos bilhetes do aeroporto correspondente
     * @param aeroporto aeroporto com os avioes que tem voos com os respetivos bilhetes
     */
    void bilhetes(Aeroporto& aeroporto);
    /**
     * Este método da update dos ficheiros dos serviços completos do aeroporto correspondente
     * @param aeroporto aeroporto onde se encontram os aviões que tem os servicos completos
     */
    void servicosCompletos(Aeroporto& aeroporto);
    /**
     * Este método da update dos ficheiros dos serviços a realizar do aeroporto correspondente
     * @param aeroporto aeroporto onde se encontram os aviões que tem os servicos a realizar
     */
    void servicosRealizar(Aeroporto& aeroporto);
    /**
     * Este método da update dos ficheiros dos transportes terrestres do aeroporto correspondente
     * @param aeroporto aeroporto que tem os respetivos transportes terrestres
     */
    void transportesTerrestres(Aeroporto& aeroporto);
public:
    /**
    * Construtor default da classe Update
    */
    Update();
    /**
     * Este método é responsavel por chamar todos os métodos encarregues de dar update de informacao para os ficheiros
     * @param gerenciarAeroportos gerenciador de aeroportos
     */
    void run(gerenciarAeroportos &gerenciarAeroportos);
};


#endif //PROJECT_UPDATE_H
