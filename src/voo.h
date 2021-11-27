#ifndef PROJECT_VOO_H
#define PROJECT_VOO_H

#include "defs.h"
#include "bilhete.h"

class Voo {
    int numVoo;
    int lotação;
    //Data dataPartida;
    //Data duraçãoVoo
    string origem,destino;
    list<bilhete> bilhetes;

};


#endif //PROJECT_VOO_H
