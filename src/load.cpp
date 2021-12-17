//
// Created by jpedr on 13/12/2021.
//

#include "load.h"
#include "defs.h"

void Load::avioes(Aeroporto& aeroporto) {
    string matriculaAviao;
    string capacidadeAviao;
    int capacidadeAviaoInt;

    string fileName = "avioes.txt";

    ifstream avioesStream;
    avioesStream.open(fileName);


    if(avioesStream.is_open()){
        while (getline(avioesStream,matriculaAviao)){
            getline(avioesStream, capacidadeAviao );
            capacidadeAviaoInt = stoi(capacidadeAviao);

            aeroporto.addAviao(matriculaAviao,capacidadeAviaoInt);
        }
    }else{
        createFile(fileName);
    }

    avioesStream.close();
}

void Load::voos(Aeroporto& aeroporto) {
    for(Aviao& a : aeroporto.getAvioes()){
        ostringstream vooFile;
        vooFile << a.getMatricula() << "_Voos.txt";

        int numVooInt, lotacaoInt;
        string numVoo, lotacao, line_file, origem,destino, numCarruagens, numPilhas, numMalas;

        tm dataPartida, duracaoVoo;

        fstream voosStream;
        voosStream.open(vooFile.str());
        if(voosStream.is_open()){
            while(getline(voosStream, numVoo)){
                numVooInt = stoi(numVoo);
                getline(voosStream, lotacao );
                lotacaoInt = stoi(lotacao);
                getline(voosStream, line_file);
                dataPartida.tm_year = stoi(line_file) -1900;
                getline(voosStream, line_file );
                dataPartida.tm_mon = stoi(line_file);
                getline(voosStream, line_file );
                dataPartida.tm_mday = stoi(line_file);
                getline(voosStream, line_file);
                dataPartida.tm_hour = stoi(line_file);
                getline(voosStream, line_file );
                dataPartida.tm_min  = stoi(line_file);
                getline(voosStream,  line_file);
                duracaoVoo.tm_hour =  stoi(line_file);
                getline(voosStream,  line_file);
                duracaoVoo.tm_min = stoi(line_file);
                getline(voosStream,  origem);
                getline(voosStream,  destino);
                getline(voosStream, numCarruagens);
                getline(voosStream, numPilhas);
                getline(voosStream, numMalas);


                Voo v(numVooInt, lotacaoInt, dataPartida, duracaoVoo, origem, destino, stoi(numCarruagens), stoi(numPilhas), stoi(numMalas));
                a.addVoo(v);
            }
            voosStream.close();
        }else{
            createFile(vooFile.str());
        }

    }
}

void Load::bilhetes(Aeroporto& aeroporto) {
    for(Aviao& a : aeroporto.getAvioes()){
        for(Voo& v : a.getPlanoVoo()){
            ostringstream bilheteFile;
            bilheteFile << a.getMatricula() << "_" << v.getNumVoo() << "_Bilhetes.txt";

            string nome, idade, CC, temBagagemStr, bagagemAutoStr;
            int idadeInt, CCInt;
            bool temBagagem;

            fstream bilheteStream;
            bilheteStream.open(bilheteFile.str());
            if(bilheteStream.is_open()) {
                while (getline(bilheteStream, nome)) {
                    getline(bilheteStream, idade);
                    idadeInt = stoi(idade);
                    getline(bilheteStream, CC);
                    CCInt = stoi(CC);
                    getline(bilheteStream, temBagagemStr);
                    if (temBagagemStr == "1") {
                        temBagagem = true;
                    } else {
                        temBagagem = false;
                    }
                    Passageiro p(nome, idadeInt, CCInt);
                    Bilhete b(p, temBagagem);

                    getline(bilheteStream, bagagemAutoStr);
                    if (bagagemAutoStr == "1" && temBagagem) {
                        b.setBagagemAuto();
                        v.getCarrinho().addBagagemCarruagem(b);
                    }
                    v.addBilhete(b);
                }
                bilheteStream.close();
            }else{
                createFile(bilheteFile.str());
            }
        }
    }
}


Load::Load() {

}

void Load::servicosCompletos(Aeroporto &aeroporto) {
    for(Aviao& a: aeroporto.getAvioes()){
        ostringstream servicosCompletosFile;
        servicosCompletosFile << a.getMatricula() << "_servicosCompletos.txt";

        string tipoServico, funcResponsavel, dataStr;
        tm data;

        fstream servicosCompletosStream;
        servicosCompletosStream.open(servicosCompletosFile.str());

        if(servicosCompletosStream.is_open()){
            while(getline(servicosCompletosStream,tipoServico)){
                getline(servicosCompletosStream,dataStr);
                data.tm_mon = stoi(dataStr);
                getline(servicosCompletosStream,dataStr);
                data.tm_mday = stoi(dataStr);
                getline(servicosCompletosStream, dataStr);
                data.tm_hour = stoi(dataStr);
                getline(servicosCompletosStream,funcResponsavel);

                Servico s(tipoServico, data, funcResponsavel);
                a.addServicoCompleto(s);
            }
            servicosCompletosStream.close();
        }else{
            createFile(servicosCompletosFile.str());
        }

    }
}

void Load::servicosRealizar(Aeroporto &aeroporto) {
    for(Aviao& a: aeroporto.getAvioes()){
        ostringstream servicosRealizarFile;
        servicosRealizarFile << a.getMatricula() << "_servicosRealizar.txt";

        string tipoServico, funcResponsavel, dataStr;
        tm data;

        fstream servicosRealizarStream;
        servicosRealizarStream.open(servicosRealizarFile.str());
        if(servicosRealizarStream.is_open()){
            while(getline(servicosRealizarStream,tipoServico)){
                getline(servicosRealizarStream,dataStr);
                data.tm_mon = stoi(dataStr);
                getline(servicosRealizarStream,dataStr);
                data.tm_mday = stoi(dataStr);
                getline(servicosRealizarStream, dataStr);
                data.tm_hour = stoi(dataStr);
                getline(servicosRealizarStream,funcResponsavel);

                Servico s(tipoServico, data, funcResponsavel);
                a.addServicoRealizar(s);
            }
            servicosRealizarStream.close();
        }else{
            createFile(servicosRealizarFile.str());
        }
    }
}

void Load::transportesTerrestres(Aeroporto& aeroporto) {
    string tipoTransporte,distancia,hora,min;
    tm horario;

    string transportesFile = "transportes.txt";
    fstream transportesStream;

    transportesStream.open(transportesFile);
    if(transportesStream.is_open()){
        while(getline(transportesStream,tipoTransporte)){
            getline(transportesStream,distancia);
            getline(transportesStream,hora);
            getline(transportesStream,min);

            horario.tm_hour = stoi(hora);
            horario.tm_min = stoi(min);
            horario.tm_mday = 1;
            horario.tm_mon = 1;
            horario.tm_year = 80;

            const TranspTerrestre t(tipoTransporte,stof(distancia),horario);
            aeroporto.getTransportes().adicionarTransporte(t);
        }
    }else{
        createFile(transportesFile);
    }
}

void Load::createFile(string fileName) {
    ofstream createFile;
    createFile.open(fileName);
    createFile.close();
}

void Load::run(Aeroporto &aeroporto) {
    avioes(aeroporto);
    voos(aeroporto);
    bilhetes(aeroporto);
    servicosCompletos(aeroporto);
    servicosRealizar(aeroporto);
    transportesTerrestres(aeroporto);
}




