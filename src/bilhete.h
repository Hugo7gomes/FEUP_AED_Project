#ifndef BILHETE_H
#define BILHETE_H

#include "voo.h"
#include "passageiro.h"
#include "defs.h"

class Bilhete {
    Passageiro passageiro;
    Voo voo;
    bool temBagagem;
    bool bagagemAuto;
public:
    Bilhete();
    Bilhete(Passageiro p , Voo v, bool b);
    Passageiro getPassageiro() const;
    Voo getVoo() const;
    bool gettemBagagem() const;
    bool getBagagemAuto() const;
    void setBagagemAuto();
};


#endif //PROJECT_BILHETE_H
