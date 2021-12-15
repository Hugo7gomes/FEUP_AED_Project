//
// Created by jpedr on 12/12/2021.
//

#include "Aeroporto.h"

struct compareByMatricula{
    bool operator() (Aviao a, Aviao b){
        return a.getMatricula() < b.getMatricula();
    }
};

struct compareByCapacidade{
    bool operator() (Aviao a, Aviao b){
        return a.getCapacidade() <= b.getCapacidade();
    }
};



void Aeroporto::showAvioes() {
    if (avioes.empty()) {
        cout << "Atualmente, o aeroporto nao tem avioes" << endl;
        return;
    } else {
        Menus::showMenuAskOrdenacaoAvioes();
        int inputOrdenacaoAvioes;
        input::inputInt(inputOrdenacaoAvioes);
        while(inputOrdenacaoAvioes != 1 && inputOrdenacaoAvioes != 2){
            input::inputInt(inputOrdenacaoAvioes);
        }

        if(inputOrdenacaoAvioes == 1){
            avioes.sort(compareByMatricula());
        }else{
            avioes.sort(compareByCapacidade());
        }

        cout << "Os avioes disponiveis sao" << endl;
        for (Aviao &a: avioes) {
            cout << a.getMatricula() << endl;
        }
        Menus::showMenuAskAlterarAviao();
        int inputAlterarAviao;
        input::inputInt(inputAlterarAviao);
        while (inputAlterarAviao != 0 && inputAlterarAviao != 1) {
            input::inputInt(inputAlterarAviao);
            Menus::showMenuAskAlterarAviao();
        }
        if (inputAlterarAviao == 1) {
            alterarAviao(procurarAviao());
        }
    }
}

void Aeroporto::addAviao(string matricula, int c) {
    Aviao aviao(matricula, c);

    avioes.push_back(aviao);
}

void Aeroporto::removeAviao() {
    cout << "Introduza matricula" << endl;
    string matricula;
    input::inputStr(matricula);

    list<Aviao>::iterator avioesIt = avioes.begin();
    for (avioesIt; avioesIt != avioes.end(); avioesIt++) {
        if (avioesIt->getMatricula() == matricula) {
            avioes.erase(avioesIt);
            break;
        }
    }
}

void Aeroporto::deleteVoo(Aviao &aviao) {
    int numVoo;

    cout << "Introduza o numero de Voo a apagar" << endl;
    input::inputInt(numVoo);

    if (aviao.eliminarVoo(numVoo)) {
        cout << "Voo eliminado com sucesso" << endl;
    } else {
        cout << "Voo nao existe" << endl;
    }
}

void Aeroporto::alterarAviao(Aviao &aviao) {

    bool isAlterarAviao = true;
    int inputMenuAlterarAviao;
    while (isAlterarAviao) {
        Menus::showMenuAlterarAviao();
        input::inputInt(inputMenuAlterarAviao);
        while (inputMenuAlterarAviao != 0 && inputMenuAlterarAviao != 1 && inputMenuAlterarAviao != 2 &&
               inputMenuAlterarAviao != 3 && inputMenuAlterarAviao != 4 && inputMenuAlterarAviao != 5 &&
               inputMenuAlterarAviao != 6 && inputMenuAlterarAviao != 7 && inputMenuAlterarAviao != 8 ) {

            Menus::showMenu();
            input::inputInt(inputMenuAlterarAviao);

        }
        switch (inputMenuAlterarAviao) {
            case 1:
                criarVoo(aviao);
                break;
            case 2:
                deleteVoo(aviao);
                break;
            case 3:
                verVoo(aviao);
                break;
            case 4:
                ordenarVoos(aviao);
                aviao.mostrarVoos();
                break;
            case 5:
                criarServicoRealizar(aviao);
                break;
            case 6:
                mostrarServicoRealizar(aviao);
                break;
            case 7:
                realizarServico(aviao);
                break;
            case 8:
                mostrarServicosCompletos(aviao);
                break;
            case 0:
                isAlterarAviao = false;
                break;
        }

    }

}

void Aeroporto::run() {
    bool isRunnig = true;
    int inputMenu;

    while (isRunnig) {
        Menus::showMenu();
        input::inputInt(inputMenu);
        while (inputMenu != 0 && inputMenu != 1 && inputMenu != 2 && inputMenu != 3 && inputMenu != 4 && inputMenu != 5) {
            Menus::showMenu();
            input::inputInt(inputMenu);
        }
        switch (inputMenu) {
            case 1:
                showAvioes();
                break;
            case 2: {
                struct inputStruct informacaoAviao = inputMatriculaCapacidade();
                addAviao(informacaoAviao.matricula, informacaoAviao.capacidade);
                break;
            }
            case 3:
                removeAviao();
                break;
            case 4:
                alterarAviao(procurarAviao());
                break;
            case 5:
                comprarBilhetes();
                break;
            case 0:
                isRunnig = false;
                break;
        }
    }
}

Aviao &Aeroporto::procurarAviao() {
    string matriculaAlterar;

    while (true) {
        cout << "Introduza matricula de aviao a alterar" << endl;
        input::inputMatricula(matriculaAlterar);

        for (Aviao &a: avioes) {

            if (a.getMatricula() == matriculaAlterar) {
                return a;
            }
        }
    }
}

void Aeroporto::criarVoo(Aviao &aviao) {
    int numVoo;
    int lotacao;
    tm dataPartida;
    tm duracaoVoo;
    string origem, destino;

    cout << "Introduza o numero de Voo" << endl;
    input::inputInt(numVoo);

    cout << "Introduza a lotacao do Voo" << endl;
    input::inputInt(lotacao);

    int ano;
    cout << "Introduza o ano da data de Partida" << endl;
    input::inputInt(ano);
    while (ano> 2020) {
        input::inputInt(ano);
    }
    dataPartida.tm_year = ano-1900;

    cout << "Introduza o mes da data de Partida" << endl;
    input::inputInt(dataPartida.tm_mon);
    while (dataPartida.tm_mon > 12) {
        input::inputInt(dataPartida.tm_mon);
    }

    cout << "Introduza o dia da data de Partida" << endl;
    input::inputInt(dataPartida.tm_mday);
    while (dataPartida.tm_mday > 31) {
        input::inputInt(dataPartida.tm_mday);
    }


    cout << "Introduza a hora da data de Partida" << endl;
    input::inputInt(dataPartida.tm_hour);
    while (dataPartida.tm_hour > 23) {
        input::inputInt(dataPartida.tm_hour);
    }


    cout << "Introduza os min da data de Partida" << endl;
    input::inputInt(dataPartida.tm_min);
    while (dataPartida.tm_min > 60) {
        input::inputInt(dataPartida.tm_min);
    }


    cout << "Introduza as horas de Voo" << endl;
    input::inputInt(duracaoVoo.tm_hour);
    while (duracaoVoo.tm_hour > 60) {
        input::inputInt(duracaoVoo.tm_hour);
    }

    cout << "Introduza os minutos de Voo" << endl;
    input::inputInt(dataPartida.tm_min);
    while (duracaoVoo.tm_min > 60) {
        input::inputInt(dataPartida.tm_min);
    }

    cout << "Introduza o origem do Voo" << endl;
    input::inputStr(origem);

    cout << "Introduza o destino do Voo" << endl;
    input::inputStr(destino);

    Voo voo(numVoo, lotacao, dataPartida, duracaoVoo, origem, destino);
    aviao.addVoo(voo);

}

void Aeroporto::comprarBilhetes() {
    Aviao &aviao = procurarAviao();

    Voo &voo = aviao.procurarVoo();

    int numBilhetes;
    cout << "Introduza o numero de bilhetes a comprar" << endl;
    input::inputInt(numBilhetes);

    if ((aviao.getCapacidade() - voo.getLotacao()) >= numBilhetes) {
        for (int i = 0; i < numBilhetes; i++) {
            Passageiro p = criarPassageiro();
            cout << "Tem bagagem?" << endl;
            cout << "1) Sim" << endl;
            cout << "0) Nao" << endl;
            bool bagagem = false;
            bool bagagemAuto = false;
            int inputBagagem;
            int inputBagagemAuto;
            Menus::showMenuAskTemBagagem();
            input::inputInt(inputBagagem);
            while (inputBagagem != 0 && inputBagagem != 1 ) {
                input::inputInt(inputBagagem);
                Menus::showMenuAskTemBagagem();
            }
            if (inputBagagem == 1) {
                bagagem = true;
                Menus::showMenuAskBagagemAuto();
                input::inputInt(inputBagagemAuto);
                while (inputBagagemAuto != 0 && inputBagagemAuto != 1) {
                    Menus::showMenuAskBagagemAuto();
                    input::inputInt(inputBagagemAuto);
                }
                if(inputBagagemAuto == 1){
                    bagagemAuto = true;
                }
            }

            Bilhete b(p, bagagem);
            if (bagagemAuto) {
                b.setBagagemAuto();
            }
            voo.addBilhete(b);
            voo.setLotacao(voo.getLotacao() - 1);
        }
    } else {
        cout << "Numero de lugares indisponivel" << endl;
    }
}

Passageiro Aeroporto::criarPassageiro() {
    string nome;
    cout << "Introduza o nome do Passageiro" << endl;
    input::inputStr(nome);

    cout << "Introduza a idade do Passageiro" << endl;
    int idade;
    input::inputInt(idade);


    cout << "Introduza o numero de CC do Passageiro" << endl;
    int CC;
    input::inputInt(CC);


    Passageiro p(nome, idade, CC);
    return p;
}

inputStruct Aeroporto::inputMatriculaCapacidade() {
    int c;
    string matricula;

    cout << "Introduza a matricula do Aviao" << endl;


    bool checkMatricula;
    do{
        checkMatricula = false;
        input::inputMatricula(matricula);
        for(Aviao& a: avioes) {
            if (a.getMatricula() == matricula) {
                cout << "Matricula ja existe, escolha outra" << endl;
                checkMatricula = true;
                break;
            }
        }
    } while (checkMatricula);


    cout << "Introduza a capacidade do Aviao" << endl;
    input::inputInt(c);

    return inputStruct(matricula, c);
}

list<Aviao> &Aeroporto::getAvioes() {
    return avioes;
}

void Aeroporto::verVoo(Aviao &a) {
    bool isVerVoo = true;
    int inputMenuVerVoo;
    Voo &v = a.procurarVoo();
    while (isVerVoo) {
        Menus::showMenuVoo(v);
        input::inputInt(inputMenuVerVoo);
        while (inputMenuVerVoo != 0 && inputMenuVerVoo != 1 && inputMenuVerVoo != 2) {
            input::inputInt(inputMenuVerVoo);
            Menus::showMenuVoo(v);
        }
        switch (inputMenuVerVoo) {
            case 1:
                verBilhete(v);
                break;
            case 2:
                removerBilhete(v);
                break;
            case 0:
                isVerVoo = false;
                break;
        }

    }
}

void Aeroporto::verBilhete(Voo &voo) {
    int id;
    if(voo.getBilhetes().empty()){
        cout << "Nao existem bilhetes registados" << endl;
        return;
    }
    while (true) {
        cout << "Introduza o id do Bilhete, 0 para voltar" << endl;
        input::inputInt(id);
        for (Bilhete &b: voo.getBilhetes()) {
            if (b.getID() == id) {
                cout << "Nome: " << b.getPassageiro().getNome() << endl;
                cout << "Idade: " << b.getPassageiro().getIdade() << endl;
                cout << "CC: " << b.getPassageiro().getCC() << endl;
                cout << "Tem bagagem: " << b.gettemBagagem() << endl;
                cout << "Quer bagagem automatica: " << b.getBagagemAuto() << endl;
                cout << "///////////////////////////////" << endl;
                return;
            }
        }
        if (id == 0) {
            return;
        }
    }
}

void Aeroporto::removerBilhete(Voo& voo) {
    int id;
    cout << "Introduza id do bilhete a remover" << endl;
    input::inputInt(id);
    if(voo.removeBilhete(id)){
        cout << "Bilhete removido com sucesso" << endl;
    }else{
        cout << "Bilhete não existe" << endl;
    }

}

void Aeroporto::mostrarServicoRealizar(Aviao &aviao) {

    if (aviao.getNumServicosRealizar() != 0) {
        Servico &s = aviao.getServicoRealizar();
        cout << s.getTipoServico() << endl;
        cout << s.getFuncResponsavel() << endl;
        cout << s.getData().tm_mon << "/" << s.getData().tm_mday << " " << s.getData().tm_hour << "-"
             << s.getData().tm_min;
        cout << endl;
    } else {
        cout << "Nenhum serviCo em fila" << endl;
    }
}

void Aeroporto::mostrarServicosCompletos(Aviao &aviao) {
    int inputOrdenarServicosCompletos;

    Menus::showMenuAskOrdenacaoServicosCompletos();

    input::inputInt(inputOrdenarServicosCompletos);
    while(inputOrdenarServicosCompletos != 1 && inputOrdenarServicosCompletos!=2 && inputOrdenarServicosCompletos!=3){
        input::inputInt(inputOrdenarServicosCompletos);
    }

    aviao.ordenarServicosCompletos(inputOrdenarServicosCompletos);

    for (Servico &s: aviao.getservicosCompletos()) {
        cout << s.getTipoServico() << endl;
        cout << s.getFuncResponsavel() << endl;
        cout << s.getData().tm_mon << "/" << s.getData().tm_mday << " " << s.getData().tm_hour << "-"
             << s.getData().tm_min << endl;
        cout << "-----------------------------------------" << endl;
    }
}

void Aeroporto::criarServicoRealizar(Aviao &aviao) {
    int tipoServicoInt;
    string tipoServico;
    Menus::showMenuAskTipoServico();

    input::inputInt(tipoServicoInt);
    while (tipoServicoInt != 0 && tipoServicoInt != 1) {
        input::inputInt(tipoServicoInt);
    }

    string funcResponsavel;
    cout << "Introduza o nome do funcionario Responsavel" << endl;
    input::inputStr(funcResponsavel);


    tm data;
    cout << "Introduza o mes em que o servico vai ser realizado: " << endl;
    input::inputInt(data.tm_mon);
    while (data.tm_mon >= 12) {
        input::inputInt(data.tm_mon);
    }

    cout << "Introduza o dia em que o servico vai ser realizado:" << endl;
    input::inputInt(data.tm_mday);
    while (data.tm_mday >= 31) {
        input::inputInt(data.tm_mday);
    }

    cout << "Introduza a hora em que o servico vai ser realizado:" << endl;
    input::inputInt(data.tm_hour);
    while (data.tm_hour >= 23) {
        input::inputInt(data.tm_hour);
    }

    if (tipoServicoInt == 1) {
        tipoServico = "manutencao";
    } else {
        tipoServico = "limpeza";
    }

    Servico S(tipoServico, data, funcResponsavel);
    aviao.addServicoRealizar(S);

}

void Aeroporto::realizarServico(Aviao &aviao) {
    if (aviao.getNumServicosRealizar() != 0) {
        aviao.realizarServico();
    } else {
        cout << "Nenhum servico em fila" << endl;
    }
}

void Aeroporto::ordenarVoos(Aviao &aviao) {
    int inputOrdenarVoos;
    Menus::showMenuAskOrdenacaoVoos();
    input::inputInt(inputOrdenarVoos);
    while(inputOrdenarVoos != 1 && inputOrdenarVoos!=2 && inputOrdenarVoos!=3 && inputOrdenarVoos!=4 && inputOrdenarVoos!=5){
        input::inputInt(inputOrdenarVoos);
    }
    aviao.ordenarVoos(inputOrdenarVoos);
}








