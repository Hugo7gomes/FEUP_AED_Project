#ifndef SERVIÇO_H
#define SERVIÇO_H

#include "defs.h"

class Servico {
    string tipoServico;
    tm data;
    string funcResponsavel;

public:
    Servico(string tipoS, tm data, string funResponsavel);
    string getTipoServico() const;
    tm getData() const;
    string getFuncResponsavel() const;


};


#endif
