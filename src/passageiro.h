#ifndef PASSAGEIRO_H
#define PASSAGEIRO_H

#include "defs.h"

class Passageiro {
    string nome;
    int idade;
    int CC;
public:
    /**
     * Construtor default da classe Passageiro
     */
    Passageiro();
    /**
     * Construtor da classe Passageiro que inicializa o nome, a idade e o cartao de cidadao do passageiro
     * @param n nome do passageiro
     * @param i idade do passageiro
     * @param cc cartao de cidadao do passageiro
     */
    Passageiro(string n, int i, int cc);
    /**
     * este metodo retorna o nome do passageiro
     * @return nome do passageiro
     */
    string getNome() const;
    /**
     * este metodo retorna a idade do passageiro
     * @return idade do passageiro
     */
    int getIdade() const;
    /**
     * este metodo retorna o cartao de cidadao do passageiro
     * @return cartao de cidadao do passageiro
     */
    int getCC() const;
};


#endif //PROJECT_PASSAGEIRO_H
