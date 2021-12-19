//
// Created by jpedr on 25/11/2021.
//

#include "servico.h"


Servico::Servico(string tipoS, tm data, string funResponsavel) : tipoServico(tipoS), funcResponsavel(funResponsavel) {
    this->data = data;
}

string Servico::getTipoServico() const {
    return tipoServico;
}

tm Servico::getData() const {
    return data;
}

string Servico::getFuncResponsavel() const {
    return funcResponsavel;
}
