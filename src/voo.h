#ifndef VOO_H
#define VOO_H

#include "defs.h"
#include "bilhete.h"
#include "carrinhoTransporte.h"

class Voo {
    int numVoo;
    int lotacao;
    tm dataPartida;
    tm duracaoVoo;
    string origem,destino;
    list<Bilhete> bilhetes;
    carrinhoTransporte carrinho;

public:
    Voo();
    /**
     *
     * @param n
     * @param lot
     * @param dPartida
     * @param durVoo
     * @param orig
     * @param dest
     * @param numCarruagens
     * @param numPilhas
     * @param numMalas
     */
    Voo(int n,int lot, struct tm dPartida, struct tm durVoo, string orig, string dest, int numCarruagens,int numPilhas,int numMalas);
    /**
     * este metodo fornece o numero de Voo de um Voo
     * @return numero Voo
     */
    int getNumVoo() const;
    /**
     * este metodo fornece a lotacao atual do voo
     * @return lotacao
     */
    int getLotacao() const;
    /**
     * este metodo fornece a data de Partida do voo
     * @return data de Partida
     */
    tm getDataPartida();
    /**
     * este metodo fornece a duracao do voo
     * @return duracao voo
     */
    tm getDuracaoVoo() const;
    /**
     * este metodo fornece a origem do voo
     * @return origem do voo
     */
    string getOrigem() const;
    /**
     * este metodo fornece o destino do voo
     * @return destino do voo
     */
    string getDestino() const;
    /**
     * este metodo fornece a lista de bilhetes do voo
     * @return lista de bilhetes
     */
    list<Bilhete> getBilhetes() const;
    /**
     * este metodo fornece o carrinho de Transporte de bagagens
     * @return carrinho de transporte
     */
    carrinhoTransporte& getCarrinho();
    /**
     * este metodo adiciona o bilhete b a lista de bilhetes
     * @param b bilhete a adicionar
     */
    void addBilhete(Bilhete b);
    /**
     * este metodo remove o bilhete b da lista de bilhetes
     * @param id id do bilhete a remover
     * @return sucesso ou insucesso da remocao do bilhete
     */
    bool removeBilhete(int id);
    /**
     * este metodo coloca a lotacao a l
     * @param l lotacao
     */
    void setLotacao(int l);

};


#endif //VOO_H
