#ifndef BILHETE_H
#define BILHETE_H

#include "voo.h"
#include "passageiro.h"
#include "defs.h"

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
