//
// Created by jpedr on 15/12/2021.
//

#ifndef PROJECT_UPDATE_H
#define PROJECT_UPDATE_H

#include "gerenciarAeroportos.h"

class Update {

public:
    Update();
    void aeroporto(gerenciarAeroportos &gerenciarAeroportos);
    void avioes(Aeroporto & aeroporto);
    void voos(Aeroporto& aeroporto);
    void bilhetes(Aeroporto& aeroporto);
    void servicosCompletos(Aeroporto& aeroporto);
    void servicosRealizar(Aeroporto& aeroporto);
    void transportesTerrestres(Aeroporto& aeroporto);
    void run(gerenciarAeroportos &gerenciarAeroportos);
};


#endif //PROJECT_UPDATE_H
