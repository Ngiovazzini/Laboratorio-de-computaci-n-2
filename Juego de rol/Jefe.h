#include "Personaje.h"
#include <string>
#include <iostream>//
// Created by Usuario on 21/06/2025.
//

#ifndef JEFE_H
#define JEFE_H



class Jefe: public Personaje{
public:
    Jefe(std:: string nombre,int salud,int ataque,int defensa,int nivel,Objeto objetoAtaque,Objeto objetoDefensa) :
        Personaje(nombre,salud,ataque,defensa,nivel,objetoAtaque,objetoDefensa) {
    }
public:
    void imrpimir_datos() override{
        std::cout <<"Nombre: "<< nombre<<"\n";
        std::cout << "Salud: "<<salud<<"\n";
        std::cout <<"Ataque: "<<ataque<<"\n";
        std::cout <<"Defensa: "<<defensa<<"\n";
        std::cout <<"Nivel:"<<nivel<<"\n";
        std::cout <<"Posion de Vida: "<< objetoAtaque.valor<<"\n";
        std::cout <<"Posion de Defensa: "<< objetoDefensa.valor<<"\n";
    }
};



#endif //JEFE_H
