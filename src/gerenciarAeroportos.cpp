//
// Created by jpedr on 17/12/2021.
//

#include "gerenciarAeroportos.h"

void gerenciarAeroportos::adicionarAeroporto() {
    string inputId;
    cout << "Introduza id do Aeroporto" << endl;
    cin.ignore(1000, '\n');
    inputId = input::inputStr();
    if(inputId == "0"){
        return;
    }
    while(checkAeroporto(inputId)){
        cout << "Aeroporto ja existe" << endl;
        inputId = input::inputStr();
        if(inputId == "0"){
            return;
        }
    }

    Aeroporto a(inputId);
    aeroportos.push_back(a);
}

void gerenciarAeroportos::adicionarAeroportoFicheiro(Aeroporto aeroporto){
    aeroportos.push_back(aeroporto);

}

void gerenciarAeroportos::removerAeroporto() {
    string inputId;
    cout << "Introduza id do Aeroporto, 0 para voltar" << endl;
    cin.ignore(1000, '\n');
    inputId = input::inputStr();
    if(inputId == "0"){
        return;
    }
    while(!checkAeroporto(inputId)){
        cout << "Aeroporto nao encontrado, introduza novo Input ou 0 para voltar" << endl;
        inputId = input::inputStr();
        if(inputId == "0"){
            return;
        }
    }

    list<Aeroporto>::iterator it = aeroportos.begin();
    for (it; it != aeroportos.end(); it++) {
        if (it->getId() == inputId) {
            aeroportos.erase(it);
            cout << "Aeroporto eliminado com sucesso" << endl;
            break;
        }
    }

}

void gerenciarAeroportos::showAeroportos() {
    if(aeroportos.empty()){
        cout << "Nao existem Aeroportos" << endl;
    }else{
        for(Aeroporto& a: aeroportos){
            cout << a.getId() << endl;
        }
    }
}



void gerenciarAeroportos::run() {
    bool isRunning = true;
    int inputMenu;
    while (isRunning) {
        Menus::showMenu();
        input::inputInt(inputMenu);
        while (inputMenu != 0 && inputMenu != 1 && inputMenu != 2 && inputMenu != 3 && inputMenu != 4) {
            input::inputInt(inputMenu);
            Menus::showMenu();
        }
        switch (inputMenu) {
            case 1:
                showAeroportos();
                break;
            case 2:
                adicionarAeroporto();
                break;
            case 3:
                removerAeroporto();
                break;
            case 4:
                verAeroporto();
                break;
            case 0:
                isRunning = false;
                break;
        }

    }
}

gerenciarAeroportos::gerenciarAeroportos() {

}

bool gerenciarAeroportos::checkAeroporto(string id) {
    for(Aeroporto& a: aeroportos){
        if(a.getId() == id){
            return true;
        }
    }
    return false;
}

list<Aeroporto> &gerenciarAeroportos::getAeroportos() {
    return aeroportos;
}

void gerenciarAeroportos::verAeroporto() {
    string inputId;
    cout << "Introduza id do Aeroporto, 0 para voltar" << endl;
    cin.ignore(1000, '\n');
    inputId = input::inputStr();
    if(inputId == "0"){
        return;
    }
    while(!checkAeroporto(inputId)){
        cout << "Aeroporto nao encontrado, introduza novo Input ou 0 para voltar" << endl;
        inputId = input::inputStr();
        if(inputId == "0"){
            return;
        }
    }

    for(Aeroporto& a:aeroportos){
        if(a.getId() == inputId){
            a.run();
        }
    }

}

string gerenciarAeroportos::checkInput() {

}


