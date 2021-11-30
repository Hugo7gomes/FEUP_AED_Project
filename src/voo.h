#ifndef VOO_H
#define VOO_H

#include "defs.h"
#include "passageiro.h"

class Voo {
    int numVoo;
    int lotacao;
    tm dataPartida;
    tm duracaoVoo;
    string origem,destino;
    list<Passageiro> passageiros;
public:
    Voo();
    Voo(int n, int lot, struct tm dPartida, struct tm durVoo, string orig, string dest);
    int getNumVoo() const;
    int getLotacao() const;
    tm getDataPartida() const;
    tm getDuracaoVoo() const;
    string getOrigem() const;
    string getDestino() const;
    list<Passageiro> getPassageiros() const;
    void addPassageiro(Passageiro p);

};


#endif //PROJECT_VOO_H
