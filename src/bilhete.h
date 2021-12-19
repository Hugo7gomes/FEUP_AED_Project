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
    /**
     * Construtor default da classe Bilhete
     */
    Bilhete();
    /**
     * Construtor da classe Bilhete
     * @param p passageiro
     * @param b se tem bagagem
     */
    Bilhete(Passageiro p, bool b);
    /**
     * Este método fornece um passageiro
     * @return passageiro
     */
    Passageiro getPassageiro() const;
    /**
     * Este método indica se o passageiro tem bagagem ou não
     * @return true se o passageiro tiver bagagem
     */
    bool getTemBagagem() const;
    /**
     * Este método indica se o passageiro quer bagagem automática ou não
     * @return true se o passageiro quiser bagagem automática
     */
    bool getBagagemAuto() const;
    /**
     * Este método coloca a bagagemAuto a true
     */
    void setBagagemAuto();
    /**
     * Este método fornece o id do bilhete
     * @return id do bilhete
     */
    int getID();
};


#endif //PROJECT_BILHETE_H
