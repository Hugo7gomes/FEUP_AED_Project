#ifndef TRANSPTERRESTRE_H
#define TRANSPTERRESTRE_H

#include "defs.h"

class TranspTerrestre {
    static int idAux;
    int id;
    string tipoTransporte;
    float distancia;
    tm horario;

public:
    TranspTerrestre();
    TranspTerrestre(string tipoT, float d, tm h);
    string getTipoTransporte() const;
    float getDistancia() const;
    tm getHorario() const;
    bool operator<(const TranspTerrestre& t) const;
    bool operator==(const TranspTerrestre& t) const;
};


#endif //TRANSPTERRESTRE_H
