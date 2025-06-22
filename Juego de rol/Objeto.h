//
// Created by Usuario on 21/06/2025.
//

#ifndef OBJETO_H
#define OBJETO_H
#include <string>
#include <iostream>

class Objeto {
public:
    std::string nombre;
    std::string tipo;
    int valor;
    int usos;
public:
    Objeto(std::string nombre, std::string tipo, int valor, int usos) {
        this->nombre=nombre;
        this->tipo=tipo;
        this->valor=valor;
        this->usos=usos;
    }

public:
    bool uso() {
        if (usos >= 1) {
            std::cout<<"Este objeto fue utilizado"<<std::endl;
            return true;
        }else {
            usos+=1;
            return false;
        }
    }
};



#endif //OBJETO_H
