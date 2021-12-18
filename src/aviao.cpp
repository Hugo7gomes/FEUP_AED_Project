//
// Created by jpedr on 25/11/2021.
//

#include "aviao.h"

Aviao::Aviao(string m, int c) : matricula(m), capacidade(c) {
}

int Aviao::getCapacidade() const {
    return capacidade;
}

string Aviao::getMatricula() const {
    return matricula;
}

list <Voo> &Aviao::getPlanoVoo() {
    return planoVoo;
}

void Aviao::addVoo(Voo v) {
    planoVoo.push_back(v);
}

void Aviao::addServicoRealizar(Servico &s) {
    servicosParaRealizar.push(s);
}


//adiciona serviço realizado aos completos e retira da queue
void Aviao::realizarServico() {
    servicosCompletos.push_back(getServicoRealizar());
    servicosParaRealizar.pop();
}

bool Aviao::eliminarVoo(int numVoo) {
    list<Voo>::iterator iteradorVoo = planoVoo.begin();
    for (iteradorVoo; iteradorVoo != planoVoo.end(); iteradorVoo++) {
        if (iteradorVoo->getNumVoo() == numVoo) {
            planoVoo.erase(iteradorVoo);
            return true;
        }
    }
    return false;
}

void Aviao::mostrarVoos() {
    if (planoVoo.size() == 0) {
        cout << "Este aviao nao possui voos";
        return;
    }
    for (Voo &voo: planoVoo) {
        cout << voo.getNumVoo() << endl;
    }
}

Voo& Aviao::procurarVoo(int numVoo) {
    for (Voo &v: planoVoo) {
        if (v.getNumVoo() == numVoo) {
            return v;
        }
    }

}

list <Servico> &Aviao::getservicosCompletos() {
    return servicosCompletos;
}

Servico &Aviao::getServicoRealizar() {
    return servicosParaRealizar.front();
}

int Aviao::getNumServicosRealizar() {
    return servicosParaRealizar.size();
}

void Aviao::addServicoCompleto(Servico &s) {
    servicosCompletos.push_back(s);
}

queue <Servico> &Aviao::getServicosRealizar() {
    return servicosParaRealizar;
}

struct compareByNumVoo {
    bool operator()(Voo a, Voo b) {
        return a.getNumVoo() < b.getNumVoo();
    }
};

struct compareByDataPartida {
    bool operator()(Voo a, Voo b) {
        struct tm tm1 = a.getDataPartida();
        struct tm tm2 = b.getDataPartida();
        time_t t1 = mktime(&tm1);
        time_t t2 = mktime(&tm2);
        return difftime(t1, t2) < 0.0;
    }
};

struct compareByDuracaoVoo {
    bool operator()(Voo a, Voo b) {
        struct tm tm1 = a.getDuracaoVoo();
        tm1.tm_mday = 1;
        tm1.tm_mon = 1;
        tm1.tm_year = 80;
        struct tm tm2 = b.getDuracaoVoo();
        tm2.tm_mday = 1;
        tm2.tm_mon = 1;
        tm2.tm_year = 80;
        time_t t1 = mktime(&tm1);
        time_t t2 = mktime(&tm2);
        return difftime(t1, t2) > 0.0;
    }
};

struct compareByOrigem {
    bool operator()(Voo &a, Voo &b) {
        return a.getOrigem() < b.getOrigem();
    }
};

struct compareByDestino {
    bool operator()(Voo &a, Voo &b) {
        return a.getDestino() < b.getDestino();
    }
};


void Aviao::ordenarVoos(int inputOrdenarVoos) {

    switch (inputOrdenarVoos) {
        case 1:
            planoVoo.sort(compareByNumVoo());
            break;
        case 2:
            planoVoo.sort(compareByDataPartida());
            break;
        case 3:
            planoVoo.sort(compareByDuracaoVoo());
            break;
        case 4:
            planoVoo.sort(compareByOrigem());
            break;
        case 5:
            planoVoo.sort(compareByDestino());
            break;
    }
}

struct compareByTipoServico {
    bool operator()(Servico &a, Servico &b) {
        return a.getTipoServico() < b.getTipoServico();
    }
};

struct compareByData {
    bool operator()(Servico &a, Servico &b) {
        struct tm tm1 = a.getData();
        struct tm tm2 = b.getData();
        tm1.tm_year = 80;
        tm2.tm_year = 80;
        time_t t1 = mktime(&tm1);
        time_t t2 = mktime(&tm2);
        return difftime(t1, t2) < 0.0;
    }
};

struct compareByfuncResponsavel {
    bool operator()(Servico &a, Servico &b) {
        return a.getFuncResponsavel() < b.getFuncResponsavel();

    }
};

void Aviao::ordenarServicosCompletos(int inputOrdenarServicosCompletos) {

    switch (inputOrdenarServicosCompletos) {
        case 1:
            servicosCompletos.sort(compareByTipoServico());
            break;
        case 2:
            servicosCompletos.sort(compareByData());
            break;
        case 3:
            servicosCompletos.sort(compareByfuncResponsavel());
            break;
    }
}

bool Aviao::checkVoo(int numVoo) {
    for (Voo &v: planoVoo) {
        if (v.getNumVoo() == numVoo) {
            return true;
        }
    }
    return false;
}








