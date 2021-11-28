#ifndef PASSAGEIRO_H
#define PASSAGEIRO_H

#include "defs.h"

class Passageiro {
    string nome;
    char sex;
    int idade;
    int CC;
public:
    Passageiro(string n, char sex, int i, int cc);
    string getNome() const;
    char getSex() const;
    int getIdade() const;
    int getCC() const;
};


#endif //PROJECT_PASSAGEIRO_H
