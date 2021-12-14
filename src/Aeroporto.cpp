//
// Created by jpedr on 12/12/2021.
//

#include "Aeroporto.h"

void Aeroporto::showMenu() const {
    cout << "Aeroporto Lia" << endl;
    cout << "1) Mostrar Avioes" << endl;
    cout << "2) Adicionar Aviao" << endl;
    cout << "3) Apagar Aviao"  << endl;
    cout << "4) Editar Aviao" << endl;
    cout << "5) Comprar Bilhetes" << endl;
    cout << "0) Exit" << endl;
}

void Aeroporto::showMenuAlterarAviao() const {
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

void Aeroporto::showMenuVoo(Voo& v) const {
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


void Aeroporto::showAvioes(){
    if(avioes.empty()){
        cout << "Atualmente, o aeroporto nao tem avioes" << endl;
        return;
    }else{
        cout << "Os avioes disponiveis sao" << endl;
        for( Aviao a : avioes){
            cout << a.getMatricula() << endl;
        }
        cout << "Deseja alterar algum aviao?" << endl;
        cout << "1) Sim" << endl;
        cout << "0) Nao" << endl;
        int inputAlterarAviao;
        cin >> inputAlterarAviao;
        while ( inputAlterarAviao != 0 && inputAlterarAviao != 1 || cin.fail())
        {
            cout << "Input invalido, insira novamente!" << endl;
            cout << "Deseja alterar algum aviao?" << endl;
            cout << "1) Sim" << endl;
            cout << "0) Nao" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            cin >> inputAlterarAviao;
        }
        if(inputAlterarAviao == 1){
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
    cin >> matricula;

    list<Aviao>::iterator avioesIt = avioes.begin();
    for(avioesIt;avioesIt != avioes.end(); avioesIt++){
        if(avioesIt->getMatricula() == matricula){
            avioes.erase(avioesIt);
        }
    }
}

void Aeroporto::deleteVoo(Aviao &aviao) {
    int numVoo;

    cout << "Introduza o numero de Voo a apagar" << endl;
    cin >> numVoo;
    while ( cin.fail())
    {
        cout << "Input invalido, insira novamente!" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        cin >> numVoo;
    }

    if(aviao.eliminarVoo(numVoo)){
        cout << "Voo eliminado com sucesso" << endl;
    }else{
        cout << "Voo não existe" << endl;
    }
}


void Aeroporto::alterarAviao(Aviao& aviao) {

    bool isAlterarAviao = true;
    int inputMenuAlterarAviao;
    while(isAlterarAviao){
        showMenuAlterarAviao();
        cin >> inputMenuAlterarAviao;
        while (inputMenuAlterarAviao != 0 && inputMenuAlterarAviao != 1 && inputMenuAlterarAviao != 2 && inputMenuAlterarAviao != 3 && inputMenuAlterarAviao != 4 && inputMenuAlterarAviao != 5 && inputMenuAlterarAviao != 6 && inputMenuAlterarAviao != 7 && inputMenuAlterarAviao != 8|| cin.fail())
        {
            cout << "Input invalido, insira novamente!" << endl;
            showMenu();
            cin.clear();
            cin.ignore(1000, '\n');
            cin >> inputMenuAlterarAviao;
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

    while(isRunnig){
        showMenu();
        cin >> inputMenu;
        while ( inputMenu != 0 && inputMenu != 1 && inputMenu != 2 && inputMenu != 3  && inputMenu != 4 && inputMenu != 5|| cin.fail())
        {
            cout << "Input invalido, insira novamente!" << endl;
            showMenu();
            cin.clear();
            cin.ignore(1000, '\n');
            cin >> inputMenu;
        }
        switch (inputMenu) {
            case 1:
                showAvioes();
                break;
            case 2:
                int c;
                addAviao(inputMatriculaCapacidade().matricula, inputMatriculaCapacidade().capacidade);
                break;
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

Aviao& Aeroporto::procurarAviao() {
    string matriculaAlterar;

    while(true){
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Introduza matricula de aviao a alterar" << endl;
        cin >> matriculaAlterar;
        for(Aviao& a : avioes){
            if(a.getMatricula() == matriculaAlterar){
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
    string origem,destino;

    cout << "Introduza o numero de Voo" << endl;
    cin >> numVoo;
    while (cin.fail())
    {
        cout << "Input invalido, insira novamente!" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        cin >> numVoo;
    }

    cout << "Introduza a lotacao do Voo" << endl;
    cin >> lotacao;
    while (cin.fail())
    {
        cout << "Invalid input, enter again!" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        cin >> lotacao;
    }

    cout << "Introduza o mes da data de Partida" << endl;
    cin >> dataPartida.tm_mon;
    while (dataPartida.tm_mon > 12 || cin.fail())
    {
        cout << "Input invalido, insira novamente!" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        cin >> dataPartida.tm_mon;
    }

    cout << "Introduza o dia da data de Partida" << endl;
    cin >> dataPartida.tm_mday;
    while (dataPartida.tm_mday > 31||cin.fail())
    {
        cout << "Input invalido, insira novamente!" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        cin >> dataPartida.tm_mday;
    }

    cout << "Introduza a hora da data de Partida" << endl;
    cin >> dataPartida.tm_hour;
    while (dataPartida.tm_hour> 23||cin.fail())
    {
        cout << "Input invalido, insira novamente!" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        cin >> dataPartida.tm_hour;
    }

    cout << "Introduza os min da data de Partida" << endl;
    cin >> dataPartida.tm_min;
    while (dataPartida.tm_min > 60 || cin.fail())
    {
        cout << "Input invalido, insira novamente!" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        cin >> dataPartida.tm_min;
    }

    cout << "Introduza as horas de Voo" << endl;
    cin >> duracaoVoo.tm_hour;
    while (duracaoVoo.tm_hour> 60 || cin.fail())
    {
        cout << "Input invalido, insira novamente!" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        cin >> duracaoVoo.tm_hour;
    }

    cout << "Introduza os minutos de Voo" << endl;
    cin >> duracaoVoo.tm_min;
    while (duracaoVoo.tm_min > 60 || cin.fail())
    {
        cout << "Input invalido, insira novamente!" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        cin >> duracaoVoo.tm_min;
    }

    cout << "Introduza o origem do Voo" << endl;
    cin >> origem;

    cout << "Introduza o destino do Voo" << endl;
    cin >> destino;

    Voo voo(numVoo, lotacao, dataPartida, duracaoVoo, origem, destino);
    aviao.addVoo(voo);

}

void Aeroporto::comprarBilhetes() {
    Aviao& aviao = procurarAviao();

    Voo& voo = aviao.procurarVoo();

    int numBilhetes;
    cout << "Introduza o numero de bilhetes a comprar" << endl;
    cin >> numBilhetes;
    while (cin.fail())
    {
        cout << "Input invalido, insira novamente!" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        cin >> numBilhetes;
    }

    if((aviao.getCapacidade() - voo.getLotacao()) >= numBilhetes){
        for(int i = 0; i < numBilhetes; i++){
            Passageiro p = criarPassageiro();
            cout << "Tem bagagem?" << endl;
            cout << "1) Sim" << endl;
            cout << "0) Nao" << endl;
            bool bagagem = false;
            bool bagagemAuto = false;
            int inputBagagem;
            int inputBagagemAuto;
            cin >> inputBagagem;
            while ( inputBagagem != 0 && inputBagagem != 1 || cin.fail())
            {
                cout << "Input invalido, insira novamente!" << endl;
                cout << "Deseja alterar algum aviao?" << endl;
                cout << "1) Sim" << endl;
                cout << "0) Nao" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                cin >> inputBagagem;
            }
            if(inputBagagem == 1){
                bagagem = true;
                cout << "Deseja check-in de bagagem automático?" << endl;
                cout << "1) Sim" << endl;
                cout << "0) Nao" << endl;
                cin >> inputBagagemAuto;
                while ( inputBagagemAuto != 0 && inputBagagemAuto != 1 || cin.fail())
                {
                    cout << "Deseja check-in de bagagem automatico?" << endl;
                    cout << "1) Sim" << endl;
                    cout << "0) Nao" << endl;
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cin >> inputBagagemAuto;
                }
                bagagemAuto = true;
            }

            Bilhete b(p,bagagem);
            if(bagagemAuto){
                b.setBagagemAuto();
            }
            voo.addBilhete(b);
            voo.setLotacao(voo.getLotacao() - 1);
        }
    }else{
        cout << "Numero de lugares indisponivel" << endl;
    }
}

Passageiro Aeroporto::criarPassageiro() {
    string nome;
    cout << "Introduza o nome do Passageiro" << endl;
    cin.clear();
    cin.ignore(1000, '\n');
    getline(cin, nome);

    cout << "Introduza a idade do Passageiro" << endl;
    int idade;
    cin >> idade;
    while (cin.fail())
    {
        cout << "Input invalido, insira novamente!" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        cin >> idade;
    }

    cout << "Introduza o numero de CC do Passageiro" << endl;
    int CC;
    cin >> CC;
    while (cin.fail())
    {
        cout << "Input invalido, insira novamente!" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        cin >> CC;
    }

    Passageiro p(nome, idade, CC);
    return p;
}

input Aeroporto::inputMatriculaCapacidade() {
    int c;
    string matricula;

    cout << "Introduza a matricula do Aviao" << endl;
    cin >> matricula;

    cout << "Introduza a capacidade do Aviao" << endl;
    cin >> c;

    return input(matricula, c);
}

list<Aviao> &Aeroporto::getAvioes() {
    return avioes;
}

void Aeroporto::verVoo(Aviao& a) {
    bool isVerVoo = true;
    int inputMenuVerVoo;
    Voo& v = a.procurarVoo();
    while(isVerVoo){
        showMenuVoo(v);
        cin >> inputMenuVerVoo;
        while ( inputMenuVerVoo != 0 && inputMenuVerVoo != 1 && inputMenuVerVoo != 2|| cin.fail()){
            cout << "Input invalido, insira novamente!" << endl;
            showMenuVoo(v);
            cin.clear();
            cin.ignore(1000, '\n');
            cin >> inputMenuVerVoo;
        }
        switch(inputMenuVerVoo){
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

void Aeroporto::verBilhete(Voo& voo) {
    int id;
    while(true){
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Introduza o id do Bilhete, ctr-Z para voltar" << endl;
        cin >> id;
        for(Bilhete& b : voo.getBilhetes()){
            if(b.getID() == id){
                cout << b.getID() << endl;
                cout << "Nome: " <<  b.getPassageiro().getNome() << endl;
                cout << "Idade: " << b.getPassageiro().getIdade() << endl;
                cout << "CC: " << b.getPassageiro().getCC() << endl;
                cout << "Tem bagagem: " << b.gettemBagagem() << endl;
                cout << "Quer bagagem automatica: " <<  b.getBagagemAuto() << endl;
                cout << "///////////////////////////////" << endl;
                return;
            }
        }
        if(id == 0){
            return;
        }
    }
}

void Aeroporto::removerBilhete(Voo& voo) {
    Bilhete b = voo.procurarBilhete();
    voo.removeBilhete(b.getID());
}

void Aeroporto::mostrarServicoRealizar(Aviao &aviao) {

    if(aviao.getNumServicosRealizar()  != 0){
        Servico& s = aviao.getServicoRealizar();
        cout << s.getTipoServico() << endl;
        cout << s.getFuncResponsavel() << endl;
        cout << s.getData().tm_mon << "/" << s.getData().tm_mday << " " << s.getData().tm_hour << "-" << s.getData().tm_min;
        cout << endl;
    }else{
        cout << "Nenhum serviCo em fila" << endl;
    }


}

void Aeroporto::mostrarServicosCompletos(Aviao &aviao) {
    for(Servico& s: aviao.getservicosCompletos()){
        cout << s.getTipoServico() << endl;
        cout << s.getFuncResponsavel() << endl;
        cout << s.getData().tm_mon << "/" << s.getData().tm_mday << " " << s.getData().tm_hour << "-" << s.getData().tm_min << endl;
        cout << "-----------------------------------------" << endl;
    }
}

void Aeroporto::criarServicoRealizar(Aviao& aviao) {
    int tipoServicoInt;
    string tipoServico;
    cout << "Introduza o tipo de Servico:" << endl;
    cout << "0) limpeza" << endl;
    cout << "1) manutencao " << endl;

    cin >> tipoServicoInt;
    while ( tipoServicoInt != 0 && tipoServicoInt != 1|| cin.fail()){
        cin.clear();
        cin.ignore(1000, '\n');
        cin >> tipoServicoInt;
    }

    string funcResponsavel;
    cout << "Introduza o nome do funcionario Responsavel" << endl;
    cin.clear();
    cin.ignore(1000, '\n');
    getline(cin, funcResponsavel);



    tm data;
    cout << "Introduza o mes em que o servico vai ser realizado: " << endl;
    cin >> data.tm_mon;
    while (data.tm_mon >= 12|| cin.fail())
    {
        cout << "Input invalido, insira novamente!" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        cin >> data.tm_mon;
    }

    cout << "Introduza o dia em que o servico vai ser realizado:" << endl;
    cin >> data.tm_mday;
    while (data.tm_mday >= 31||cin.fail())
    {
        cout << "Input invalido, insira novamente!" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        cin >> data.tm_mday;
    }

    cout << "Introduza a hora em que o servico vai ser realizado:" << endl;
    cin >> data.tm_hour;
    while (data.tm_hour >= 23 || cin.fail())
    {
        cout << "Input invalido, insira novamente!" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        cin >> data.tm_hour;
    }

    if(tipoServicoInt == 1){
        tipoServico = "manutencao";
    }else{
        tipoServico = "limpeza";
    }

    Servico S(tipoServico, data, funcResponsavel);
    aviao.addServicoRealizar(S);

}

void Aeroporto::realizarServico(Aviao &aviao) {
        if(aviao.getNumServicosRealizar() != 0){
            aviao.realizarServico();
        }else{
            cout << "Nenhum servico em fila" << endl;
        }
}







