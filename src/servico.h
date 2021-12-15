#ifndef SERVICO_H
#define SERVICO_H

#include "defs.h"

class Servico {
    string tipoServico;
    tm data;
    string funcResponsavel;

public:
    Servico(string tipoS, tm data, string funResponsavel);
    string getTipoServico() const;
    tm getData() const;
    string getFuncResponsavel();


};


#endif
