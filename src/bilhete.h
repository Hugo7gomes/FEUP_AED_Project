#ifndef PROJECT_BILHETE_H
#define PROJECT_BILHETE_H

#include "defs.h"
#include "voo.h"
#include "passageiro.h"

class Bilhete {
    Passageiro passageiro;
    Voo voo;
    bool bagagemAuto;
public:
    Bilhete(Passageiro p , Voo v);
    Passageiro getPassageiro() const;
    Voo getVoo() const;
    bool getBagagenAuto() const;
    void setBagagemAuto();
};


#endif //PROJECT_BILHETE_H
