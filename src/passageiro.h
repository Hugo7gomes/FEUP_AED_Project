#ifndef PASSAGEIRO_H
#define PASSAGEIRO_H

#include "defs.h"

class Passageiro {
    string nome;
    int idade;
    int CC;
public:
    Passageiro();
    Passageiro(string n, int i, int cc);
    string getNome() const;
    int getIdade() const;
    int getCC() const;
};


#endif //PROJECT_PASSAGEIRO_H
