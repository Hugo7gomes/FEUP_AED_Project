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
    /**
     *
     * @param p
     * @param b
     */
    Bilhete(Passageiro p, bool b);
    /**
     * este metodo fornece um passageiro
     * @return passageiro
     */
    Passageiro getPassageiro() const;
    /**
     * este metodo indica se o passageiro tem bagagem ou não
     * @return true se o passageiro tiver bagagem
     */
    bool gettemBagagem() const;
    /**
     * este metodo indica se o passageiro quer bagagem automática ou não
     * @return true se o passageiro quiser bagagem automática
     */
    bool getBagagemAuto() const;
    /**
     * este metodo coloca a bagagemAuto a true
     */
    void setBagagemAuto();
    /**
     * este metodo fornece o id do bilhete
     * @return id do bilhete
     */
    int getID();
};


#endif //PROJECT_BILHETE_H
