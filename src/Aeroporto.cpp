//
// Created by jpedr on 12/12/2021.
//

#include "Aeroporto.h"

struct compareByMatricula {
    bool operator()(const Aviao &a, const Aviao &b) {
        return a.getMatricula() < b.getMatricula();
    }
};

struct compareByCapacidade {
    bool operator()(const Aviao &a, const Aviao &b) {
        return a.getCapacidade() <= b.getCapacidade();
    }
};


void Aeroporto::showAvioes() {
    if (avioes.empty()) {
        cout << "Atualmente, o aeroporto nao tem avioes" << endl;
        cout << endl;
        return;
    } else {
        Menus::showMenuAskOrdenacaoAvioes();
        int inputOrdenacaoAvioes;
        input::inputInt(inputOrdenacaoAvioes);
        while (inputOrdenacaoAvioes != 1 && inputOrdenacaoAvioes != 2) {
            input::inputInt(inputOrdenacaoAvioes);
        }

        if (inputOrdenacaoAvioes == 1) {
            avioes.sort(compareByMatricula());
        } else {
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
            alterarAviao();
        }
    }
}

void Aeroporto::addAviao(string matricula, int c) {
    Aviao aviao(matricula, c);
    avioes.push_back(aviao);
}

void Aeroporto::adicionarAviao() {
    string matricula;
    int capacidade;
    cout << "Introduza matricula do aviao" << endl;
    cin.ignore(1000, '\n');
    matricula = input::inputStr();
    if (matricula == "0") {
        return;
    }
    while (checkAviao(matricula)) {
        cout << "Aviao ja existe" << endl;
        matricula = input::inputStr();
        if (matricula == "0") {
            return;
        }
    }


    cout << "Introduza a capacidade do Aviao" << endl;
    input::inputInt(capacidade);

    Aviao aviao(matricula, capacidade);
    avioes.push_back(aviao);
}


void Aeroporto::removeAviao() {
    cout << "Introduza matricula, 0 para voltar" << endl;
    string matricula;
    input::inputMatricula(matricula);
    if (matricula == "0")
        return;
    bool checkMatricula = false;
    for (Aviao &a: avioes) {
        if (a.getMatricula() == matricula) {
            checkMatricula = true;
            break;
        }
    }
    while (!checkMatricula) {
        cout << "Matricula nao existe" << endl;
        input::inputMatricula(matricula);
        if (matricula == "0")
            return;
        for (Aviao &a: avioes) {
            if (a.getMatricula() == matricula) {
                checkMatricula = true;
                break;
            }
        }
    }

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
    if (aviao.getPlanoVoo().empty()) {
        cout << "Nao existem voos" << endl;
        return;
    }
    cout << "Introduza o numero de Voo a apagar" << endl;
    input::inputInt(numVoo);
    if (numVoo == 0) {
        return;
    }
    while (!aviao.eliminarVoo(numVoo)) {
        cout << "Voo nao existe" << endl;
        input::inputInt(numVoo);
        if (numVoo == 0) {
            return;
        }
    }
    cout << "Voo eliminado com sucesso" << endl;

}


void Aeroporto::alterarAviao() {
    string matricula;
    int capacidade;
    cout << "Introduza matricula do aviao" << endl;
    cin.ignore(1000, '\n');
    matricula = input::inputStr();
    if (matricula == "0") {
        return;
    }
    while (!checkAviao(matricula)) {
        cout << "Aviao nao existe" << endl;
        matricula = input::inputStr();
        if (matricula == "0") {
            return;
        }
    }


    Aviao &aviao = procurarAviao(matricula);


    bool isAlterarAviao = true;
    int inputMenuAlterarAviao;
    while (isAlterarAviao) {
        Menus::showMenuAlterarAviao();
        input::inputInt(inputMenuAlterarAviao);
        while (inputMenuAlterarAviao != 0 && inputMenuAlterarAviao != 1 && inputMenuAlterarAviao != 2) {

            Menus::showMenuAlterarAviao();
            input::inputInt(inputMenuAlterarAviao);

        }
        switch (inputMenuAlterarAviao) {
            case 1:
                TratarVoos(aviao);
                break;
            case 2:
                TratarServicos(aviao);
                break;
            case 0:
                isAlterarAviao = false;
                break;
        }

    }

}

void Aeroporto::TratarVoos(Aviao &aviao) {
    bool isAlterarVoo = true;
    int inputMenuAlterarVoo;
    while (isAlterarVoo) {
        Menus::showMenuAlterarAviaoVoos();
        input::inputInt(inputMenuAlterarVoo);
        while (inputMenuAlterarVoo != 0 && inputMenuAlterarVoo != 1 && inputMenuAlterarVoo != 2 &&
               inputMenuAlterarVoo != 3 && inputMenuAlterarVoo != 4) {

            Menus::showMenuAlterarAviaoVoos();
            input::inputInt(inputMenuAlterarVoo);
        }

        switch (inputMenuAlterarVoo) {
            case 1:
                ordenarVoos(aviao);
                aviao.mostrarVoos();
                break;

            case 2:
                if(aviao.getPlanoVoo().empty()){
                    cout << "Nao existem voos neste aviao" << endl;
                    break;
                }
                verVoo(aviao);
                break;

            case 3:
                criarVoo(aviao);
                break;

            case 4:
                deleteVoo(aviao);
                break;
            case 0:
                isAlterarVoo = false;
                break;
        }
    }
}

void Aeroporto::TratarServicos(Aviao &aviao) {
    bool isAlterarServico = true;
    int inputMenuAlterarServico;
    while (isAlterarServico) {
        Menus::showMenuAlterarAviaoServicos();
        input::inputInt(inputMenuAlterarServico);
        while (inputMenuAlterarServico != 0 && inputMenuAlterarServico != 1 && inputMenuAlterarServico != 2 &&
               inputMenuAlterarServico != 3 && inputMenuAlterarServico != 4) {

            Menus::showMenuAlterarAviaoServicos();
            input::inputInt(inputMenuAlterarServico);
        }
        switch (inputMenuAlterarServico) {
            case 1:
                mostrarServicosCompletos(aviao);
                break;
            case 2:
                mostrarServicoRealizar(aviao);
                break;
            case 3:
                criarServicoRealizar(aviao);
                break;
            case 4:
                realizarServico(aviao);
                break;
            case 0:
                isAlterarServico = false;
                break;
        }
    }
}

void Aeroporto::tratarAvioes() {
    bool isRunning = true;
    int inputMenuAvioes;

    while (isRunning) {
        cout << "Aeroporto " << id << endl;
        Menus::showMenuAvioes();
        input::inputInt(inputMenuAvioes);
        while (inputMenuAvioes != 0 && inputMenuAvioes != 1 && inputMenuAvioes != 2 && inputMenuAvioes != 3 &&
               inputMenuAvioes != 4 && inputMenuAvioes != 5) {
            cout << "Aeroporto " << id << endl;
            Menus::showMenuAvioes();
            input::inputInt(inputMenuAvioes);
        }
        switch (inputMenuAvioes) {
            case 1:
                showAvioes();
                break;
            case 2: {
                adicionarAviao();
                break;
            }
            case 3:
                if (avioes.size() == 0) {
                    cout << "Atualmente, nao existem avioes neste aeroporto" << endl;
                    cout << endl;
                    break;
                }
                removeAviao();
                break;
            case 4: {
                if (avioes.size() == 0) {
                    cout << "Atualmente, nao existem avioes neste aeroporto" << endl;
                    cout << endl;
                    break;
                }
                alterarAviao();
                break;
            }
            case 5:
                comprarBilhetes();
                break;
            case 0:
                isRunning = false;
                break;
        }
    }
}

void Aeroporto::tratarTransportes() {
    int inputMenuTransportes;
    bool isRunning = true;

    while (isRunning) {
        Menus::showMenuTransportesTerrestres();
        input::inputInt(inputMenuTransportes);
        while (inputMenuTransportes != 0 && inputMenuTransportes != 1 && inputMenuTransportes != 2 &&
               inputMenuTransportes != 3 && inputMenuTransportes != 4) {
            Menus::showMenuTransportesTerrestres();
            input::inputInt(inputMenuTransportes);
        }

        switch (inputMenuTransportes) {
            case 1:
                Transportes.mostrarTransportes();
                break;
            case 2: {
                TranspTerrestre t;
                Transportes.inputTransporte(t);
                Transportes.adicionarTransporte(t);
                break;
            }

            case 3: {
                TranspTerrestre t;
                Transportes.inputTransporte(t);
                Transportes.removerTransporte(t);
                break;
            }
            case 4:
                Transportes.procurarTransporte();
                break;
            case 0:
                isRunning = false;
                break;
        }
    }
}

void Aeroporto::run() {
    int inputMenu;
    bool isRunning = true;

    while (isRunning) {
        Menus::showMenuAeroporto();
        input::inputInt(inputMenu);
        while (inputMenu != 0 && inputMenu != 1 && inputMenu != 2) {
            Menus::showMenuAeroporto();
            input::inputInt(inputMenu);
        }

        switch (inputMenu) {
            case 1:
                tratarAvioes();
                break;
            case 2:
                tratarTransportes();
                break;
            case 0:
                isRunning = false;
                break;
        }
    }
}

Aviao &Aeroporto::procurarAviao(string matricula) {

    for (Aviao &a: avioes) {
        if (a.getMatricula() == matricula) {
            return a;
        }
    }
}

void Aeroporto::criarVoo(Aviao &aviao) {
    int numVoo, lotacao, numCarruagens, numPilhas, numMalas;
    tm dataPartida;
    tm duracaoVoo;
    string origem, destino;

    cout << "Introduza o numero de Voo, 0 para voltar" << endl;

    bool checkNumVoo;
    do {
        checkNumVoo = false;
        input::inputInt(numVoo);
        if (numVoo == 0) {
            return;
        }
        for (Voo &v: aviao.getPlanoVoo()) {
            if (v.getNumVoo() == numVoo) {
                cout << "Numero de Voo ja existe, escolha outra" << endl;
                checkNumVoo = true;
                break;
            }
        }
    } while (checkNumVoo);


    int ano;
    cout << "Introduza o ano da data de Partida" << endl;
    input::inputInt(ano);
    while (ano < 2020) {
        cout << "Input invalido, insira novamente!" << endl;
        input::inputInt(ano);
    }
    dataPartida.tm_year = ano - 1900;

    cout << "Introduza o mes da data de Partida" << endl;
    input::inputInt(dataPartida.tm_mon);
    while (dataPartida.tm_mon > 12) {
        cout << "Input invalido, insira novamente!" << endl;
        input::inputInt(dataPartida.tm_mon);
    }

    cout << "Introduza o dia da data de Partida" << endl;
    input::inputInt(dataPartida.tm_mday);
    while (dataPartida.tm_mday > 31) {
        cout << "Input invalido, insira novamente!" << endl;
        input::inputInt(dataPartida.tm_mday);
    }


    cout << "Introduza a hora da data de Partida" << endl;
    input::inputInt(dataPartida.tm_hour);
    while (dataPartida.tm_hour > 23) {
        cout << "Input invalido, insira novamente!" << endl;
        input::inputInt(dataPartida.tm_hour);
    }


    cout << "Introduza os min da data de Partida" << endl;
    input::inputInt(dataPartida.tm_min);
    while (dataPartida.tm_min > 60) {
        cout << "Input invalido, insira novamente!" << endl;
        input::inputInt(dataPartida.tm_min);
    }


    cout << "Introduza as horas de Voo" << endl;
    input::inputInt(duracaoVoo.tm_hour);
    while (duracaoVoo.tm_hour > 60) {
        cout << "Input invalido, insira novamente!" << endl;
        input::inputInt(duracaoVoo.tm_hour);
    }

    cout << "Introduza os minutos de Voo" << endl;
    input::inputInt(dataPartida.tm_min);
    while (duracaoVoo.tm_min > 60) {
        cout << "Input invalido, insira novamente!" << endl;
        input::inputInt(dataPartida.tm_min);
    }

    cout << "Introduza o origem do Voo" << endl;
    cin.ignore(1000, '\n');
    origem = input::inputStr();

    cout << "Introduza o destino do Voo" << endl;
    destino = input::inputStr();


    cout << "Introduza o numero de carruagens por carrinho de transporte" << endl;
    input::inputInt(numCarruagens);

    cout << "Introduza o numero de pilhas de malas por carruagem" << endl;
    input::inputInt(numPilhas);

    cout << "Introduza o numero de malas por pilha" << endl;
    input::inputInt(numMalas);
    Voo voo(numVoo, 0, dataPartida, duracaoVoo, origem, destino, numCarruagens, numPilhas, numMalas);
    aviao.addVoo(voo);

}

void Aeroporto::comprarBilhetes() {
    string matricula;
    cout << "Introduza matricula do aviao" << endl;
    cin.ignore(1000, '\n');
    matricula = input::inputStr();
    if (matricula == "0") {
        return;
    }
    while (!checkAviao(matricula)) {
        cout << "Aviao nao existe" << endl;
        matricula = input::inputStr();
        if (matricula == "0") {
            return;
        }
    }
    Aviao &aviao = procurarAviao(matricula);

    int numVoo;
    cout << "Introduza numero do voo" << endl;

    input::inputInt(numVoo);
    if (numVoo == 0) {
        return;
    }
    while (!aviao.checkVoo(numVoo)) {
        cout << "Voo nao existe" << endl;
        input::inputInt(numVoo);
        if (numVoo == 0) {
            return;
        }
    }


    Voo &voo = aviao.procurarVoo(numVoo);

    int numBilhetes;
    cout << "Introduza o numero de bilhetes a comprar" << endl;
    input::inputInt(numBilhetes);

    if ((aviao.getCapacidade() - voo.getLotacao()) >= numBilhetes) {
        for (int i = 0; i < numBilhetes; i++) {
            Passageiro p = criarPassageiro();
            bool bagagem = false;
            bool bagagemAuto = false;
            int inputBagagem;
            int inputBagagemAuto;
            Menus::showMenuAskTemBagagem();
            input::inputInt(inputBagagem);
            while (inputBagagem != 0 && inputBagagem != 1) {
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
                if (inputBagagemAuto == 1) {
                    bagagemAuto = true;
                }
            }

            Bilhete b(p, bagagem);
            if (bagagemAuto) {
                if (voo.getCarrinho().addBagagemCarruagem(b)) {
                    b.setBagagemAuto();
                } else {
                    cout << "Este voo tem a lotacao de malas automaticas cheia" << endl;
                }
            }
            voo.addBilhete(b);
            voo.setLotacao(voo.getLotacao() + 1);
        }
    } else {
        cout << "Numero de lugares indisponivel" << endl;
    }
}

Passageiro Aeroporto::criarPassageiro() {
    string nome;
    cout << "Introduza o nome do Passageiro" << endl;
    cin.ignore(1000, '\n');
    nome = input::inputStr();

    cout << "Introduza a idade do Passageiro" << endl;
    int idade;
    input::inputInt(idade);


    cout << "Introduza o numero de CC do Passageiro" << endl;
    int CC;
    input::inputInt(CC);


    Passageiro p(nome, idade, CC);
    return p;
}


list<Aviao> &Aeroporto::getAvioes() {
    return avioes;
}

void Aeroporto::verVoo(Aviao &a) {
    bool isVerVoo = true;
    int inputMenuVerVoo;

    int numVoo;
    cout << "Introduza numero do voo" << endl;

    input::inputInt(numVoo);
    if (numVoo == 0) {
        return;
    }
    while (!a.checkVoo(numVoo)) {
        cout << "Voo nao existe" << endl;
        input::inputInt(numVoo);
        if (numVoo == 0) {
            return;
        }
    }

    Voo &v = a.procurarVoo(numVoo);

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
    if (voo.getBilhetes().empty()) {
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

void Aeroporto::removerBilhete(Voo &voo) {
    int id;
    cout << "Introduza id do bilhete a remover" << endl;
    if (voo.getBilhetes().empty()) {
        cout << "Nao existem bilhetes" << endl;
        return;
    }
    input::inputInt(id);
    if (id == 0) {
        return;
    }
    while (!voo.removeBilhete(id)) {
        cout << "Bilhete nao existe" << endl;
        input::inputInt(id);
        if (id == 0) {
            return;
        }
    }
    voo.setLotacao(voo.getLotacao() - 1);
    cout << "Bilhete eliminado com sucesso" << endl;

}

void Aeroporto::mostrarServicoRealizar(Aviao &aviao) {

    if (aviao.getNumServicosRealizar() != 0) {
        Servico &s = aviao.getServicoRealizar();
        cout << s.getTipoServico() << endl;
        cout << s.getFuncResponsavel() << endl;
        cout << s.getData().tm_mon << "/" << s.getData().tm_mday << " " << s.getData().tm_hour << endl;
        cout << endl;
    } else {
        cout << "Nenhum servico em fila" << endl;
    }
}

void Aeroporto::mostrarServicosCompletos(Aviao &aviao) {
    int inputOrdenarServicosCompletos;

    if (aviao.getservicosCompletos().empty()) {
        cout << "Ainda nao foi realizado nenhum servico" << endl;
        cout << endl;
        return;
    }
    Menus::showMenuAskOrdenacaoServicosCompletos();

    input::inputInt(inputOrdenarServicosCompletos);
    while (inputOrdenarServicosCompletos != 1 && inputOrdenarServicosCompletos != 2 &&
           inputOrdenarServicosCompletos != 3) {
        input::inputInt(inputOrdenarServicosCompletos);
    }

    aviao.ordenarServicosCompletos(inputOrdenarServicosCompletos);

    for (Servico &s: aviao.getservicosCompletos()) {
        cout << s.getTipoServico() << endl;
        cout << s.getFuncResponsavel() << endl;
        cout << s.getData().tm_mon << "/" << s.getData().tm_mday << " " << s.getData().tm_hour << ":00" << endl;
        cout << "-----------------------------------------" << endl;
    }
}

void Aeroporto::criarServicoRealizar(Aviao &aviao) {
    int tipoServicoInt;
    string tipoServico;


    Menus::showMenuAskTipoServico();

    input::inputInt(tipoServicoInt);
    while (tipoServicoInt != 0 && tipoServicoInt != 1 && tipoServicoInt != 2) {
        cout << "Input invalido, insira novamente" << endl;
        input::inputInt(tipoServicoInt);
    }
    switch (tipoServicoInt) {
        case 0:
            return;
        case 1:
            tipoServico = "Limpeza";
            break;
        case 2:
            tipoServico = "Manutencao";
            break;
    }

    string funcResponsavel;
    cout << "Introduza o nome do funcionario Responsavel" << endl;
    cin.ignore(1000, '\n');
    funcResponsavel = input::inputStr();


    tm data;
    cout << "Introduza o mes em que o servico vai ser realizado: " << endl;
    input::inputInt(data.tm_mon);
    while (data.tm_mon > 12) {
        cout << "Input invalido, mes tem que ser entre 1 e 12" << endl;
        input::inputInt(data.tm_mon);
    }

    cout << "Introduza o dia em que o servico vai ser realizado:" << endl;
    input::inputInt(data.tm_mday);
    while (data.tm_mday > 31) {
        cout << "Input invalido, dia tem que ser entre 1 e 31" << endl;
        input::inputInt(data.tm_mday);
    }

    cout << "Introduza a hora em que o servico vai ser realizado:" << endl;
    input::inputInt(data.tm_hour);
    while (data.tm_hour > 23) {
        cout << "Input invalido, hora tem que ser entre 0 e 23" << endl;
        input::inputInt(data.tm_hour);
    }


    Servico S(tipoServico, data, funcResponsavel);
    aviao.addServicoRealizar(S);

}

void Aeroporto::realizarServico(Aviao &aviao) {
    if (aviao.getNumServicosRealizar() != 0) {
        aviao.realizarServico();
        cout << "Servico realizado com sucesso" << endl;
        cout << endl;
    } else {
        cout << "Nenhum servico em fila" << endl;
    }
}

void Aeroporto::ordenarVoos(Aviao &aviao) {
    int inputOrdenarVoos;
    Menus::showMenuAskOrdenacaoVoos();
    input::inputInt(inputOrdenarVoos);
    while (inputOrdenarVoos != 1 && inputOrdenarVoos != 2 && inputOrdenarVoos != 3 && inputOrdenarVoos != 4 &&
           inputOrdenarVoos != 5) {
        input::inputInt(inputOrdenarVoos);
    }
    aviao.ordenarVoos(inputOrdenarVoos);
}

Aeroporto::Aeroporto(string id) {
    this->id = id;
}

gerenciarTransportes &Aeroporto::getTransportes() {
    return Transportes;
}

string Aeroporto::getId() {
    return id;
}

bool Aeroporto::checkAviao(string matricula) {
    for (Aviao &a: avioes) {
        if (a.getMatricula() == matricula) {
            return true;
        }
    }
    return false;
}











