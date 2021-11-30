//
// Created by jpedr on 25/11/2021.
//

#include "transpTerrestre.h"

TranspTerrestre::TranspTerrestre(string tipoT, float d, tm h) : tipoTransporte(tipoT), distancia(d) {
    horario = h;
}

string TranspTerrestre::getTipoTransporte() const {
    return tipoTransporte;
}

float TranspTerrestre::getDistancia() const {
    return distancia;
}

tm TranspTerrestre::getHorario() const {
    return horario;
}


