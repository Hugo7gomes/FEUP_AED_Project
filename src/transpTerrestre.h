#ifndef PROJECT_TRANSPTERRESTRE_H
#define PROJECT_TRANSPTERRESTRE_H

#include "defs.h"

class TranspTerrestre {
    string tipoTransporte;
    float distancia;
    tm horario;

public:
    TranspTerrestre(string tipoT, float d, tm h);
    string getTipoTransporte() const;
    float getDistancia() const;
    tm getHorario() const;
};


#endif //PROJECT_TRANSPTERRESTRE_H
