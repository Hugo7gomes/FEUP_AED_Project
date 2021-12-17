//
// Created by jpedr on 14/12/2021.
//

#ifndef PROJECT_MENUS_H
#define PROJECT_MENUS_H
#include "defs.h"
#include "Aeroporto.h"

namespace Menus {
    void showMenu();
    void showMenuAlterarAviao();
    void showMenuAlterarAviaoVoos();
    void showMenuAlterarAviaoServicos();
    void showMenuAvioes();
    void showMenuVoo(Voo& v);
    void showMenuTransportesTerrestres();
    void showMenuAskAlterarAviao();
    void showMenuAskTemBagagem();
    void showMenuAskBagagemAuto();
    void showMenuAskTipoServico();
    void showMenuAskOrdenacaoAvioes();
    void showMenuAskOrdenacaoVoos();
    void showMenuAskOrdenacaoServicosCompletos();
};


#endif //PROJECT_MENUS_H
