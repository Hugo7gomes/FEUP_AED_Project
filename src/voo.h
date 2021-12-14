#ifndef VOO_H
#define VOO_H

#include "defs.h"
#include "bilhete.h"

class Voo {
    int numVoo;
    int lotacao;
    tm dataPartida;
    tm duracaoVoo;
    string origem,destino;
    list<Bilhete> bilhetes;
public:
    Voo();
    Voo(int n, int lot, struct tm dPartida, struct tm durVoo, string orig, string dest);
    int getNumVoo() const;
    int getLotacao() const;
    tm getDataPartida() const;
    tm getDuracaoVoo() const;
    string getOrigem() const;
    string getDestino() const;
    list<Bilhete> getBilhetes() const;
    void addBilhete(Bilhete b);
    void setLotacao(int l);
    bool removeBilhete(int id);
    Bilhete& procurarBilhete();
};


#endif //PROJECT_VOO_H
