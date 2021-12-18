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
    /**
     * construtor default da classe TranspTerrestre
     */
    TranspTerrestre();
    /**
     * construtor da classe TranspTerrestre que inicializa o tipo de transporte, a distancia do transporte e o horario do transporte
     * @param tipoT tipo de transporte
     * @param d distancia do transporte
     * @param h horario do transporte
     */
    TranspTerrestre(string tipoT, float d, tm h);
    /**
     * este metodo retorna o tipo de transporte
     * @return tipo de transporte
     */
    string getTipoTransporte() const;
    /**
     * este metodo retorna a distancia do aeroporto ao transporte
     * @return distancia do aeroporto ao transporte
     */
    float getDistancia() const;
    /**
     * este metodo retorna o horario do transporte
     * @return horario do transporte
     */
    tm getHorario() const;
    /**
     * overload do operador menor
     * @param t transporte a ser comparado
     * @return true caso o transporte seja menor
     */
    bool operator<(const TranspTerrestre& t) const;
    /**
     * overload do operador "igual a"
     * @param t transporte a ser comparado
     * @return true caso o transporte seja igual
     */
    bool operator==(const TranspTerrestre& t) const;
};


#endif //TRANSPTERRESTRE_H
