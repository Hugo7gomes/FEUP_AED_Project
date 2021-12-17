//
// Created by jpedr on 17/12/2021.
//

#include "gerenciarTransportes.h"

void gerenciarTransportes::mostrarTransportes() {
    if(transportes.isEmpty()){
        cout << "Nenhum Transporte guardado" << endl;
        return;
    }
    BSTItrIn<TranspTerrestre> itr(transportes);
    while(!itr.isAtEnd()){
        showTransporte(itr.retrieve());
        itr.advance();
    }
}

bool gerenciarTransportes::adicionarTransporte(const TranspTerrestre& t) {
    return transportes.insert(t);
}

bool gerenciarTransportes::removerTransporte(const TranspTerrestre& t) {
    return transportes.remove(t);
}

void gerenciarTransportes::showTransporteMaisProximo() {
    TranspTerrestre t = transportes.findMin();
    showTransporte(t);
}

void gerenciarTransportes::showTransporte(TranspTerrestre t) {
    cout << t.getTipoTransporte() << endl;
    cout << t.getDistancia() << endl;
    cout << t.getHorario().tm_hour  << ":" << t.getHorario().tm_min << endl;
}

bool gerenciarTransportes::procurarTransporte() {
    const TranspTerrestre& t = inputTransporte();
    TranspTerrestre aux;
    iteratorBST<TranspTerrestre> it = transportes.begin();
    while(it != transportes.end()){
        if((*it) == t ){
            cout << "Transporte encontrado" << endl;
            showTransporte(*it);
            return true;
        }else{
            if(it == transportes.begin()){
                aux = *it;
            }
            if(t < *it){
                break;
            }
            aux = *it;
        }
        it++;
    }
    cout << "Transporte nao foi encontrado. A opcao mais proxima e: " << endl;
    showTransporte(aux);
}

const TranspTerrestre& gerenciarTransportes::inputTransporte() {
    string tipoTransporte;
    float distancia;
    tm horario;

    cout << "Introduza o tipo de Transporte" << endl;
    //cout << "Introduza 0 para voltar" << endl;
    cin.ignore(1000, '\n');
    tipoTransporte = input::inputStr();
    while(tipoTransporte != "metro" && tipoTransporte != "autocarro" && tipoTransporte != "comboio"){
        cout << "Input invalido. Apenas metro, autocarro ou comboio" << endl;
        tipoTransporte = input::inputStr();
    }

    cout << "Introduza a distancia ao aeroporto" << endl;
    input::inputFloat(distancia);

    cout << "Introduza as horas a que chega o Transporte" << endl;
    input::inputInt(horario.tm_hour);
    while(horario.tm_hour >= 23){
        cout << "Input invalido, hora tem que ser entre 0 e 23" << endl;
        input::inputInt(horario.tm_hour);
    }

    cout << "Introduza os min a que chega o Transporte" << endl;
    input::inputInt(horario.tm_min);
    while(horario.tm_min>= 59){
        cout << "Input invalido, minutos tem que ser entre 0 e 59" << endl;
        input::inputInt(horario.tm_min);
    }

    horario.tm_mday = 1;
    horario.tm_mon = 1;
    horario.tm_mon = 80;

    const TranspTerrestre t(tipoTransporte, distancia, horario);
    return t;
}

BST<TranspTerrestre> &gerenciarTransportes::getTransportesBST() {
    return transportes;
}
