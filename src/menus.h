//
// Created by jpedr on 14/12/2021.
//

#ifndef PROJECT_MENUS_H
#define PROJECT_MENUS_H
#include "defs.h"
#include "Aeroporto.h"

namespace Menus {
    /**
     * Este método mostra na consola o menu inicial e as possíveis alterações aos aeoroportos
     */
    void showMenu();

    /**
     * Este método mostra na consola o menu do Aeroporto
     */
    void showMenuAeroporto();

    /**
     * Este método mostra na consola o menu para alterar os voos e serviços de um avião
     */
    void showMenuAlterarAviao();

    /**
     * Este método mostra na consola o menu para alterar voos
     */
    void showMenuAlterarAviaoVoos();

    /**
     * Este método mostra na consola o menu para alterar os serviços do avião
     */
    void showMenuAlterarAviaoServicos();

    /**
     * Este método mostra na consola o menu com as possíveis alterações aos aviões
     */
    void showMenuAvioes();

    /**
     * Este método mostra na consola um voo e as possíveis alterações aos bilhetes desse voo
     * @param v voo
     */
    void showMenuVoo(Voo& v);

    /**
     * Este método mostra na consola os transportes terrestres e suas as possíveis alterações
     */
    void showMenuTransportesTerrestres();

    /**
     * Este método mostra na consola se pretende alterar algum avião
     */
    void showMenuAskAlterarAviao();

    /**
     * Este método mostra na consola se tem bagagem
     */
    void showMenuAskTemBagagem();

    /**
     * Este método mostra na consola se pretende bagagem automática
     */
    void showMenuAskBagagemAuto();

    /**
     * Este método mostra na consola os tipos de serviço
     */
    void showMenuAskTipoServico();

    /**
     * Este método mostra na consola as possíveis formas de organizar os aviões
     */
    void showMenuAskOrdenacaoAvioes();

    /**
     * Este método mostra na consola as possíveis formas de organizar os voos
     */
    void showMenuAskOrdenacaoVoos();

    /**
     * Este método mostra na consola as possíveis formas de organizar os serviços completos
     */
    void showMenuAskOrdenacaoServicosCompletos();
};


#endif //PROJECT_MENUS_H
