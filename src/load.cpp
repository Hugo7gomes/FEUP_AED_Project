//
// Created by jpedr on 13/12/2021.
//

#include "load.h"
#include "defs.h"

void Load::avioes(Aeroporto& aeroporto) {
    string matriculaAviao;
    string capacidadeAviao;
    int capacidadeAviaoInt;

    ifstream avioesStream;
    avioesStream.open("avioes.txt");


    if(avioesStream.is_open()){
        while (getline(avioesStream,matriculaAviao)){
            getline(avioesStream, capacidadeAviao );
            capacidadeAviaoInt = stoi(capacidadeAviao);

            aeroporto.addAviao(matriculaAviao,capacidadeAviaoInt);
        }
    }

    avioesStream.close();
}

void Load::voos(Aeroporto& aeroporto) {
    for(Aviao& a : aeroporto.getAvioes()){
        ostringstream vooFile;
        vooFile << a.getMatricula() << "_Voos.txt";

        int numVooInt, lotacaoInt;
        string numVoo, lotacao, line_file, origem,destino;

        tm dataPartida, duracaoVoo;

        fstream voosStream;
        voosStream.open(vooFile.str());
        while(getline(voosStream, numVoo)){
            numVooInt = stoi(numVoo);
            getline(voosStream, lotacao );
            lotacaoInt = stoi(lotacao);
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

            Voo v(numVooInt, lotacaoInt, dataPartida, duracaoVoo, origem, destino );
            a.addVoo(v);
        }
        voosStream.close();
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
                    cout << nome << endl;
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
                    }
                    v.addBilhete(b);
                }
            }
            bilheteStream.close();
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
    }
}


