//
// Created by jpedr on 15/12/2021.
//

#include "update.h"


void Update::aeroporto(gerenciarAeroportos &gerenciarAeroportos) {
    ostringstream aeroportosFile;
    ofstream aeroportosStream;
    aeroportosStream.open("aeroportos.txt", ofstream::trunc);
    for (Aeroporto &a: gerenciarAeroportos.getAeroportos()) {
        aeroportosStream << a.getId() << endl;
    }
    aeroportosStream.close();
}


void Update::avioes(Aeroporto &aeroporto) {
    ostringstream avioesFile;
    avioesFile << aeroporto.getId() << "_Avioes.txt";
    string fileName = avioesFile.str();
    ofstream avioesStream;
    avioesStream.open(fileName, ofstream::trunc);
    for (Aviao &a: aeroporto.getAvioes()) {
        avioesStream << a.getMatricula() << endl;
        avioesStream << a.getCapacidade() << endl;
    }

    avioesStream.close();
}


void Update::voos(Aeroporto &aeroporto) {

    for (Aviao &a: aeroporto.getAvioes()) {
        ostringstream vooFile;
        vooFile << aeroporto.getId() << "_" << a.getMatricula() << "_Voos.txt";

        ofstream voosStream;
        voosStream.open(vooFile.str(), ofstream::trunc);

        for (Voo &v: a.getPlanoVoo()) {
            voosStream << v.getNumVoo() << endl;
            voosStream << v.getLotacao() << endl;
            voosStream << v.getDataPartida().tm_year << endl;
            voosStream << v.getDataPartida().tm_mon << endl;
            voosStream << v.getDataPartida().tm_mday << endl;
            voosStream << v.getDataPartida().tm_hour << endl;
            voosStream << v.getDataPartida().tm_min << endl;
            voosStream << v.getDuracaoVoo().tm_hour << endl;
            voosStream << v.getDuracaoVoo().tm_min << endl;
            voosStream << v.getOrigem() << endl;
            voosStream << v.getDestino() << endl;
            voosStream << v.getCarrinho().getNumCarruagens() << endl;
            voosStream << v.getCarrinho().getNumPilhas() << endl;
            voosStream << v.getCarrinho().getNumMalas() << endl;
        }
        voosStream.close();
    }
}

void Update::bilhetes(Aeroporto &aeroporto) {
    for (Aviao &a: aeroporto.getAvioes()) {
        for (Voo &v: a.getPlanoVoo()) {
            ostringstream bilheteFile;
            bilheteFile << aeroporto.getId() << "_" << a.getMatricula() << "_" << v.getNumVoo() << "_Bilhetes.txt";

            ofstream bilheteStream;
            bilheteStream.open(bilheteFile.str(), ofstream::trunc);
            for (Bilhete &b: v.getBilhetes()) {
                bilheteStream << b.getPassageiro().getNome() << endl;
                bilheteStream << b.getPassageiro().getIdade() << endl;
                bilheteStream << b.getPassageiro().getCC() << endl;
                bilheteStream << b.gettemBagagem() << endl;
                bilheteStream << b.getBagagemAuto() << endl;
            }
            bilheteStream.close();
        }
    }
}

void Update::servicosCompletos(Aeroporto &aeroporto) {
    for (Aviao &a: aeroporto.getAvioes()) {
        ostringstream servicosCompletosFile;
        servicosCompletosFile << aeroporto.getId() << "_" << a.getMatricula() << "_ServicosCompletos.txt";

        ofstream servicosCompletosStream;
        servicosCompletosStream.open(servicosCompletosFile.str(), ofstream::trunc);
        for (Servico &s: a.getservicosCompletos()) {
            servicosCompletosStream << s.getTipoServico() << endl;
            servicosCompletosStream << s.getData().tm_mon << endl;
            servicosCompletosStream << s.getData().tm_mday << endl;
            servicosCompletosStream << s.getData().tm_hour << endl;
            servicosCompletosStream << s.getFuncResponsavel() << endl;
        }
        servicosCompletosStream.close();
    }
}

void Update::servicosRealizar(Aeroporto &aeroporto) {
    for (Aviao &a: aeroporto.getAvioes()) {
        ostringstream servicosRealizarFile;
        servicosRealizarFile << aeroporto.getId() << "_" << a.getMatricula() << "_ServicosRealizar.txt";

        ofstream servicosRealizarStream;
        servicosRealizarStream.open(servicosRealizarFile.str(), ofstream::trunc);
        while (!a.getServicosRealizar().empty()) {
            Servico s = a.getServicoRealizar();
            servicosRealizarStream << s.getTipoServico() << endl;
            servicosRealizarStream << s.getData().tm_mon << endl;
            servicosRealizarStream << s.getData().tm_mday << endl;
            servicosRealizarStream << s.getData().tm_hour << endl;
            servicosRealizarStream << s.getFuncResponsavel() << endl;
            a.getServicosRealizar().pop();
        }
        servicosRealizarStream.close();
    }
}

void Update::transportesTerrestres(Aeroporto &aeroporto) {
    string tipoTransporte,distancia,hora,min;
    tm horario;
    ostringstream fileName;
    fileName << aeroporto.getId() << "_Transportes.txt";
    string transportesFile = fileName.str();
    ofstream transportesStream;

    transportesStream.open(transportesFile, ofstream::trunc);
    BSTItrIn<TranspTerrestre> it(aeroporto.getTransportes().getTransportesBST());
    while (!it.isAtEnd()) {
        transportesStream << it.retrieve().getTipoTransporte() << endl;
        transportesStream << it.retrieve().getDistancia() << endl;
        transportesStream << it.retrieve().getHorario().tm_hour << endl;
        transportesStream << it.retrieve().getHorario().tm_min << endl;
        it.advance();
    }

    transportesStream.close();
}

Update::Update() {

}

void Update::run(gerenciarAeroportos &gerenciarAeroportos) {
    aeroporto(gerenciarAeroportos);
    for (Aeroporto &aeroporto: gerenciarAeroportos.getAeroportos()) {
        avioes(aeroporto);
        voos(aeroporto);
        bilhetes(aeroporto);
        servicosCompletos(aeroporto);
        servicosRealizar(aeroporto);
        transportesTerrestres(aeroporto);
    }
}











