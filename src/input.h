//
// Created by jpedr on 14/12/2021.
//

#ifndef PROJECT_INPUT_H
#define PROJECT_INPUT_H
#include "defs.h"

namespace  input{
    /**
     * este metodo controla o input de inteiros
     * @param num parametro aonde é retornado o input
     */
    void inputInt(int& num);
    /**
     * este metodo controla o input de floats
     * @param num parametro aonde é retornado o input
     */
    void inputFloat(float& num);
    /**
     * este metodo controla o input de strings
     * @return string inserida pelo utilizador
     */
    string inputStr();
    /**
     * este metodo controla o input da matricula do aviao
     * @param str parametro aonde é retornado a matricula
     */
    void inputMatricula(string& str);
}

#endif //PROJECT_INPUT_H
