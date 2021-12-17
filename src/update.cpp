//
// Created by jpedr on 15/12/2021.
//

#include "update.h"

void Update::avioes(Aeroporto &aeroporto) {
    ofstream avioesStream;
    avioesStream.open("avioes.txt", ofstream::trunc);

    if(avioesStream.is_open()){
        for(Aviao& a: aeroporto.getAvioes()){
            avioesStream << a.getMatricula() << endl;
            avioesStream << a.getCapacidade() << endl;
        }
    }
}


void Update::voos(Aeroporto &aeroporto) {

    for(Aviao& a:aeroporto.getAvioes()){
        ostringstream vooFile;
        vooFile << a.getMatricula() << "_Voos.txt";

        ofstream voosStream;
        voosStream.open(vooFile.str(), ofstream::trunc);

        for(Voo& v:a.getPlanoVoo()){
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
    for(Aviao& a:aeroporto.getAvioes()){
        for(Voo& v: a.getPlanoVoo()){
            ostringstream bilheteFile;
            bilheteFile << a.getMatricula() << "_" << v.getNumVoo() << "_Bilhetes.txt";

            ofstream bilheteStream;
            bilheteStream.open(bilheteFile.str(),ofstream::trunc);
            for(Bilhete& b: v.getBilhetes()){
                bilheteStream << b.getPassageiro().getNome() << endl;
                bilheteStream << b.getPassageiro().getIdade() << endl;
                bilheteStream << b.getPassageiro().getCC() << endl;
                bilheteStream << b.gettemBagagem() <<endl;
                bilheteStream << b.getBagagemAuto() << endl;
            }
            bilheteStream.close();
        }
    }
}

void Update::servicosCompletos(Aeroporto &aeroporto) {
    for(Aviao& a:aeroporto.getAvioes()){
        ostringstream servicosCompletosFile;
        servicosCompletosFile << a.getMatricula() << "_servicosCompletos.txt";

        ofstream servicosCompletosStream;
        servicosCompletosStream.open(servicosCompletosFile.str(), ofstream::trunc);
        for(Servico& s:a.getservicosCompletos()){
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
    for(Aviao& a:aeroporto.getAvioes()){
        ostringstream servicosRealizarFile;
        servicosRealizarFile << a.getMatricula() << "_servicosRealizar.txt";

        ofstream servicosRealizarStream;
        servicosRealizarStream.open(servicosRealizarFile.str(), ofstream::trunc);
        while(!a.getServicosRealizar().empty()){
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

void Update::transportesTerrestres(Aeroporto aeroporto) {
    string transportesFile = "transportes.txt";
    fstream transportesStream;

    transportesStream.open(transportesFile, ofstream::trunc);
    BSTItrIn<TranspTerrestre> it(aeroporto.getTransportes().getTransportesBST());
    while(!it.isAtEnd()){
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

void Update::run(Aeroporto &aeroporto) {
    avioes(aeroporto);
    voos(aeroporto);
    bilhetes(aeroporto);
    servicosCompletos(aeroporto);
    servicosRealizar(aeroporto);
    transportesTerrestres(aeroporto);
}









