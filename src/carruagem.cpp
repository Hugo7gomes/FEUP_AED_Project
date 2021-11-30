//
// Created by jpedr on 30/11/2021.
//

#include "carruagem.h"

Carruagem::Carruagem(int n, int m) {
    for(int i = 0; i < n ; i++){
        vector<Bagagem> vetor(m);
        stack<Bagagem,vector<Bagagem> > stack (vetor);
    }

}
