//
// Created by jpedr on 13/12/2021.
//

#ifndef PROJECT_LOAD_H
#define PROJECT_LOAD_H

#include "Aeroporto.h"

class Load {
public:
    Load();
    void avioes(Aeroporto & aeroporto);
    void voos(Aeroporto& aeroporto);//ler os voos do aviao vooFile
    void bilhetes(Aeroporto& aeroporto);
    void servicosCompletos(Aeroporto& aeroporto);
    void servicosRealizar(Aeroporto& aeroporto);
    void transportesTerrestres(Aeroporto& aeroporto);
    void run(Aeroporto& aeroporto);
    void createFile(string fileName);
};


#endif //PROJECT_LOAD_H
