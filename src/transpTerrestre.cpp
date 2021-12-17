//
// Created by jpedr on 25/11/2021.
//

#include "transpTerrestre.h"
int TranspTerrestre :: idAux = 1;

TranspTerrestre::TranspTerrestre(string tipoT, float d, tm h) : tipoTransporte(tipoT), distancia(d) {
    horario = h;
    id = idAux;
    idAux++;
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

bool TranspTerrestre::operator<(const TranspTerrestre& t) const{
    if(this->distancia == t.getDistancia()){
        struct tm tm1 = this->horario;
        tm1.tm_mday=1;
        tm1.tm_mon =1;
        tm1.tm_year = 80;
        struct tm tm2 = t.horario;
        tm2.tm_mday=1;
        tm2.tm_mon =1;
        tm2.tm_year = 80;
        time_t t1 = mktime(&tm1);
        time_t t2 = mktime(&tm2);
        return difftime(t1,t2) >0.0;
    }else{
        return this->distancia < t.getDistancia();
    }
}

bool TranspTerrestre::operator==(const TranspTerrestre& t) const {
    return this->id == t.id;
}

TranspTerrestre::TranspTerrestre() {

}





