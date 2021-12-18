//
// Created by jpedr on 13/12/2021.
//

#ifndef PROJECT_LOAD_H
#define PROJECT_LOAD_H

#include "gerenciarAeroportos.h"

class Load {
private:

    /**
     * este metodo le do ficheiro dos aeroportos e adiciona-os á lista de aeroportos do gerenciador de aeroportos
     * @param gerenciarAeroportos gerenciador de aeroportos
     */
    void aeroporto(gerenciarAeroportos &gerenciarAeroportos);
    /**
     * este metodo le do ficheiro de avioes do aeroporto correspondente e adiciona-os à lista de avioes do aeroporto
     * @param aeroporto aeroporto a adicionar os avioes
     */
    void avioes(Aeroporto & aeroporto);
    /**
     * este metodo percorre todos avioes de certo aeroporto lendo do ficheiro correspondente os voos e adicionando-os ao plano de voo desse aviao
     * @param aeroporto aeroporto com os avioes a que se adicionam os voos
     */
    void voos(Aeroporto& aeroporto);
    /**
     * este metodo percorre todos os voos de todos avioes lendo do ficheiro correspondente os bilhetes e adcionadno-os á lista de bilhetes do voo
     * @param aeroporto aeroporto com os avioes que tem voos a que se adicionam bilhetes
     */
    void bilhetes(Aeroporto& aeroporto);
    /**
     * este metodo percorre todos os avioes do aeroporto lendo do ficheiro correspondente os servicos completos e adcionando-os à lista de servicos completos
     * @param aeroporto aeroporto com os avioes a que se adicionam servicos completos
     */
    void servicosCompletos(Aeroporto& aeroporto);
    /**
     * este metodo percorre todos os avioes do aeroporto lendo do ficheiro correspondente os servicos a realizar e adcionando-os à fila de servicos a realizar
     * @param aeroporto aeroporto com os avioes a que se adicionam servicos a realizar
     */
    void servicosRealizar(Aeroporto& aeroporto);
    /**
     * este metodo le do ficheiro de transportes terrestres do aeroporto correspondente e adiciona-os à BST de transportes do aeroporto
     * @param aeroporto aeroporto a adicionar os transportes terrestres
     */
    void transportesTerrestres(Aeroporto& aeroporto);
    /**
     * este metodo cria um ficheiro
     * @param fileName nome do ficheiro a ser criado
     */
    void createFile(string fileName);
public:
    /**
   * Construtor default da classe load
   */
    Load();
    /**
     * este metodo é responsavel por chamar todos os metodos encarregues de dar load de informacao dos ficheiros
     * @param gerenciarAeroportos
     */
    void run(gerenciarAeroportos &gerenciarAeroportos);

};


#endif //PROJECT_LOAD_H
