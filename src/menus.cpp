//
// Created by jpedr on 14/12/2021.
//

#include "menus.h"
#include "aviao.h"
namespace Menus {
    void showMenu(){
        cout << "1) Ver aeroportos" << endl;
        cout << "2) Adicionar aeroporto" << endl;
        cout << "3) Remover aeroporto" << endl;
        cout << "4) Ver aeroporto" << endl;
        cout << "0) Exit" << endl;
    }
    void showMenuAeroporto(){
        cout << "1) Avioes" << endl;
        cout << "2) Transportes Terrestres" << endl;
        cout << "0) Exit" << endl;
    }

    void showMenuAvioes()  {

        cout << "1) Mostrar Avioes" << endl;
        cout << "2) Adicionar Aviao" << endl;
        cout << "3) Apagar Aviao" << endl;
        cout << "4) Editar Aviao" << endl;
        cout << "5) Comprar Bilhetes" << endl;
        cout << "0) Exit" << endl;
    }

    void showMenuTransportesTerrestres(){
        cout << "1) Ver transportes" << endl;
        cout << "2) Adicionar Transportes" << endl;
        cout << "3) Remover Transportes" << endl;
        cout << "4) Procurar Transporte" << endl;
        cout << "0) Exit" << endl;
    }

    void showMenuAlterarAviao(){
        cout << "Menu editar Aviao" << endl;
        cout << "1) Alterar Voos" << endl;
        cout << "2) Alterar Servicos" << endl;
        cout << "0) Voltar Menu Principal" << endl;

    }

    void showMenuAlterarAviaoVoos()  {
        cout << "Menu editar Voos" << endl;
        cout << "1) Mostrar todos os Voos" << endl;
        cout << "2) Ver Voo" << endl;
        cout << "3) Adicionar Voo ao plano de Voos" << endl;
        cout << "4) Eliminar Voo do plano de Voos" << endl;
        cout << "0) Voltar Menu Principal" << endl;
    }

    void showMenuAlterarAviaoServicos(){
        cout << "Menu editar Servicos" << endl;
        cout << "1) Mostrar os servicos completos" << endl;
        cout << "2) Mostrar proximo servico a realizar" << endl;
        cout << "3) Adicionar servicos a realizar" << endl;
        cout << "4) Realizar servico" << endl;
        cout << "0) Voltar Menu Principal" << endl;
    }

    void showMenuVoo(Voo &v)  {
        cout << "Numero Voo: " << v.getNumVoo() << endl;
        cout << "Lotacao: " << v.getLotacao() << endl;
        cout << "Origem: " << v.getOrigem() << endl;
        cout << "Destino: " << v.getDestino() << endl;
        cout << "Data de Partida: " << v.getDataPartida().tm_mon << "/" << v.getDataPartida().tm_mday << endl;
        cout << v.getDataPartida().tm_hour << "-" << v.getDataPartida().tm_min << endl;
        cout << "1)Ver Bilhete" << endl;
        cout << "2)Remover Bilhete" << endl;
        cout << "0) Exit" << endl;
    }

    void showMenuAskAlterarAviao(){
        cout << "Deseja alterar algum aviao?" << endl;
        cout << "1) Sim" << endl;
        cout << "0) Nao" << endl;
    }

    void showMenuAskTemBagagem(){
        cout << "Tem bagagem?" << endl;
        cout << "1) Sim" << endl;
        cout << "0) Nao" << endl;
    }

    void showMenuAskBagagemAuto(){
        cout << "Deseja check-in de bagagem automatico?" << endl;
        cout << "1) Sim" << endl;
        cout << "0) Nao" << endl;
    }

    void showMenuAskTipoServico(){
        cout << "Introduza o tipo de Servico:" << endl;
        cout << "1) Limpeza" << endl;
        cout << "2) Manutencao " << endl;
        cout << "0) Exit" << endl;

    }

    void showMenuAskOrdenacaoAvioes() {
        cout << "Deseja ver os avioes ordenados por: " << endl;
        cout << "1) Matricula" << endl;
        cout << "2) Capacidade" << endl;

    }

    void showMenuAskOrdenacaoVoos() {
        cout << "Deseja ver os voos ordenados por: " << endl;
        cout << "1) Numero do voo" << endl;
        cout << "2) Data de Partida" << endl;
        cout << "3) Duracao do voo" << endl;
        cout << "4) Local de origem" << endl;
        cout << "5) Local de destino" << endl;
    }

    void showMenuAskOrdenacaoServicosCompletos() {
        cout << "Deseja ver os servicos completos ordenados por: " << endl;
        cout << "1) Tipo de servico" << endl;
        cout << "2) Data do servico" << endl;
        cout << "3) Funcionario responsavel" << endl;
    }


}