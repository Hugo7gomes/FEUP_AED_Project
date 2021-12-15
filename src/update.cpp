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
