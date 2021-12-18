#ifndef SERVICO_H
#define SERVICO_H

#include "defs.h"

class Servico {
    string tipoServico;
    tm data;
    string funcResponsavel;

public:
    /**
     * Construtor da classe Servico
     * @param tipoS tipo de Servico (limpeza ou manutencao)
     * @param data data do Servico
     * @param funResponsavel nome do funcionario responsavel
     */
    Servico(string tipoS, tm data, string funResponsavel);
    /**
     * este metodo fornece o tipo de Servico do Servico
     * @return tipo de Servico
     */
    string getTipoServico() const;
    /**
     * este metodo fornece a data em que se realiza o servico
     * @return data do Servico
     */
    tm getData() const;
    /**
     * este metodo fornece o nome do funcionario responsavel pelo servico
     * @return nome do funcionario responsavel
     */
    string getFuncResponsavel();


};


#endif
