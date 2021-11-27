#ifndef PROJECT_AVIÃO_H
#define PROJECT_AVIÃO_H

#include "defs.h"
#include "voo.h"



class Aviao {
    string const matricula;
    int const capacidade;
    list<Voo> planoVoo;
public:
    Aviao(string m, int c, list<Voo> planoVoo);
    int getCapacidade() const;
    string getMatricula() const;
    list<Voo> getPlanoVoo() const;
    void addVoo(Voo v);
};


#endif //PROJECT_AVIÃO_H
