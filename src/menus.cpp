//
// Created by jpedr on 14/12/2021.
//

#include "menus.h"
#include "aviao.h"
namespace Menus {
    void showMenu()  {
        cout << "Aeroporto Lia" << endl;
        cout << "1) Mostrar Avioes" << endl;
        cout << "2) Adicionar Aviao" << endl;
        cout << "3) Apagar Aviao" << endl;
        cout << "4) Editar Aviao" << endl;
        cout << "5) Comprar Bilhetes" << endl;
        cout << "0) Exit" << endl;
    }

    void showMenuAlterarAviao()  {
        cout << "Escolha o que quer alterar" << endl;
        cout << "1) Adicionar Voo ao plano de Voos" << endl;
        cout << "2) Eliminar Voo do plano de Voos" << endl;
        cout << "3) Ver Voo" << endl;
        cout << "4) Mostrar todos os Voos" << endl;
        cout << "5) Adicionar servicos a realizar" << endl;
        cout << "6) Mostrar proximo servico a realizar" << endl;
        cout << "7) Realizar servico" << endl;
        cout << "8) Mostrar os servicos completos" << endl;
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
        cout << "0) limpeza" << endl;
        cout << "1) manutencao " << endl;

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