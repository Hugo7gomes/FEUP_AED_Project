#ifndef BILHETE_H
#define BILHETE_H


#include "passageiro.h"
#include "defs.h"

class Bilhete {
    static int idAux;
    int id;
    Passageiro passageiro;
    bool temBagagem;
    bool bagagemAuto;
public:
    Bilhete();
    Bilhete(Passageiro p, bool b);
    Passageiro getPassageiro() const;
    bool gettemBagagem() const;
    bool getBagagemAuto() const;
    void setBagagemAuto();
    int getID();
};


#endif //PROJECT_BILHETE_H
