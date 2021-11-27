#ifndef PROJECT_AVIÃO_H
#define PROJECT_AVIÃO_H

#include "defs.h"
#include "voo.h"



class Aviao {
    string const matricula;
    int const capacidade;
    list<voo> planoVoo;
public:
    Aviao(string m, int c, list<voo> planoVoo);
    int getCapacidade() const;
    string getMatricula() const;
    list<voo> getPlanoVoo() const;
    void addVoo(voo v);
};


#endif //PROJECT_AVIÃO_H
